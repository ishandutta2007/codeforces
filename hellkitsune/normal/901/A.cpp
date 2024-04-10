#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200005];

int main() {
    scanf("%d", &n);
    ++n;
    forn(i, n) scanf("%d", a + i);
    int sum = 0;
    forn(i, n) sum += a[i];
    bool ok = true;
    forn(i, n - 1) if (a[i] > 1 && a[i + 1] > 1) {
        ok = false;
        break;
    }
    if (ok) {
        cout << "perfect" << endl;
        return 0;
    }
    cout << "ambiguous" << endl;
    printf("0");
    int pre = 1;
    int num = 2;
    for (int i = 1; i < n; ++i) {
        int npre = num;
        forn(j, a[i]) printf(" %d", pre), num++;
        pre = npre;
    }

    printf("\n0");
    pre = 1;
    int lst = 1;
    num = 2;
    for (int i = 1; i < n; ++i) {
        int npre = num;
        forn(j, a[i]) {
            printf(" %d", pre);
            if (pre < lst) {
                ++pre;
            }
            num++;
        }
        pre = npre;
        lst = num - 1;
    }
    puts("");
    return 0;
}