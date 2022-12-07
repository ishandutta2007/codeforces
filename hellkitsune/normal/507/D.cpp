#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, MOD;
int d[3][100], nd[3][100];

int main() {
    cin >> n >> k >> MOD;
    d[0][0] = 1;
    int mul = 1 % k;
    forn(i, n) {
        memset(nd, 0, sizeof nd);
        forn(p, 3) forn(q, k) if (d[p][q]) for (int dig = (i == n - 1); dig < 10; ++dig) {
            int nq = (q + mul * dig) % k;
            int np = p;
            if (np == 0 && dig > 0) ++np;
            if (np == 1 && nq == 0) ++np;
            nd[np][nq] = (nd[np][nq] + d[p][q]) % MOD;
        }
        mul = 10 * mul % k;
        memcpy(d, nd, sizeof nd);
    }
    int ans = 0;
    forn(i, k) ans = (ans + d[2][i]) % MOD;
    cout << ans << endl;
    return 0;
}