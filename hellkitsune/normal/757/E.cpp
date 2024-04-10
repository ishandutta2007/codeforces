#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int q, r, n;

const int MOD = int(1e9) + 7;

int f[2000005];
int rf[2000005];

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return int(res);
}

inline int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

vector<int> di[1000001];
int d[9], nd[9];

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i = 2; i <= 1000000; ++i) {
        if (!di[i].empty()) {
            continue;
        }
        di[i].pb(1);
        for (int j = 2 * i; j <= 1000000; j += i) {
            di[j].pb(1);
            for (int x = j / i; x % i == 0; x /= i) {
                ++di[j].back();
            }
        }
    }
    //cerr << clock() << endl;
    f[0] = 1;
    for (int i = 1; i < 2000005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
    }
    rf[0] = rf[1] = 1;
    for (int i = 2; i < 2000005; ++i) {
        rf[i] = (MOD - (LL)(MOD / i) * rf[MOD % i] % MOD) % MOD;
    }
    for (int i = 2; i < 2000005; ++i) {
        rf[i] = (LL)rf[i] * rf[i - 1] % MOD;
        assert((LL)f[i] * rf[i] % MOD == 1);
    }
    //cerr << clock() << endl;
    scanf("%d", &q);
    forn(_, q) {
        scanf("%d%d", &r, &n);
        --r;
        forn(i, 9) {
            d[i] = 0;
        }
        d[0] = 1;
        int ans;
        if (r == -1) {
            ans = 1;
            forn(_, di[n].size()) {
                ans = 2 * ans % MOD;
            }
        } else {
            for (int x : di[n]) {
                forn(i, 9) {
                    nd[i] = 0;
                }
                int cc = c(x + r, r);
                forn(i, 9) if (d[i]) {
                    nd[i] = (nd[i] + (LL)d[i] * cc) % MOD;
                }
                LL ccc = 0;
                forn(j, x) {
                    ccc += c(j + r, r);
                }
                cc = ccc % MOD;
                forn(i, 8) if (d[i]) {
                    nd[i + 1] = (nd[i + 1] + (LL)d[i] * cc) % MOD;
                }
                forn(i, 9) {
                    d[i] = nd[i];
                    //cerr << d[i] << ' ';
                }
                //cerr << endl;
            }
            ans = 0;
            int mul = 1;
            forn(i, 9) {
                ans = (ans + (LL)mul * d[i]) % MOD;
                mul *= 2;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}