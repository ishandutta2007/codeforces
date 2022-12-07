#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x;
int a[100005];

int main() {
    cin >> n >> x;
    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
    }
    if (n == 2) {
        if (x == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << "0 " << x << endl;
        }
        return 0;
    }
    cout << "YES" << endl;
    int xo = 0;
    forn(i, n - 1) {
        a[i] = i;
    }
    a[0] ^= 1 << 17;
    a[1] ^= 1 << 18;
    forn(i, n - 1) {
        xo ^= a[i];
    }
    xo ^= x;
    a[n - 1] = xo;
    forn(i, n) printf("%d ", a[i]);
    puts("");

//    int t = 0;
//    forn(i, n) t ^= a[i];
//    assert(t == x);
    return 0;
}