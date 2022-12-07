#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000], b[1000], c[1000];

int main() {
    cin >> n;
    a[0] = 0;
    a[1] = 1;
    b[0] = 1;
    int alen = 2;
    int blen = 1;

    forn(_, n - 1) {
        forn(i, alen + 1) c[i] = 0;
        forn(i, alen) c[i + 1] += a[i];
        forn(i, blen) c[i] += b[i];
        bool ok = true;
        forn(i, alen + 1) if (abs(c[i]) > 1) {
            ok = false;
        }
        if (!ok) {
            forn(i, alen + 1) c[i] = 0;
            forn(i, alen) c[i + 1] -= a[i];
            forn(i, blen) c[i] += b[i];
            ok = true;
            forn(i, alen + 1) if (abs(c[i]) > 1) {
                ok = false;
            }
            if (!ok) {
                cerr << "!!" << endl;
                return 0;
            }
        }
        forn(i, alen) b[i] = a[i];
        forn(i, alen + 1) a[i] = c[i];
        ++alen;
        ++blen;

//        forn(i, alen) cout << a[i] << ' ';
//        cout << endl;
//        forn(i, blen) cout << b[i] << ' ';
//        cout << endl << endl;
    }

    if (a[alen - 1] < 0) {
        forn(i, alen) a[i] *= -1;
    }
    if (b[blen - 1] < 0) {
        forn(i, blen) b[i] *= -1;
    }
    assert(a[alen - 1] == 1);
    assert(b[blen - 1] == 1);

    printf("%d\n", alen - 1);
    forn(i, alen) printf("%d ", a[i]);
    printf("\n%d\n", blen - 1);
    forn(i, blen) printf("%d ", b[i]);
    return 0;
}