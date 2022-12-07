#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;
const int INV2 = (MOD + 1) / 2;

int e[51][51];
int f[51], c[51][51];
int d[51][51];
int inv2[51];

int n;
int a[50];

int main() {
    f[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
    }
    forn(i, 51) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 51; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    inv2[0] = 1;
    forn(i, 50) inv2[i + 1] = (LL)inv2[i] * INV2 % MOD;
    forn(i, 51) forn(j, 51) {
        int &res = e[i][j];
        if (i == 0 && j == 0) {
            res = 1;
            continue;
        }
        res = 0;
        if (i > 0) {
            if (i > 1) res = (LL)e[i - 2][j] * (i - 1) % MOD;
            if (j > 0) res = (res + (LL)e[i][j - 1] * j) % MOD;
            continue;
        }
        for (int k = 3; k <= j; ++k) {
            res = (res + (LL)e[i][j - k] * c[j - 1][k - 1] % MOD * f[k - 1] % MOD * INV2) % MOD;
        }
    }

    if (0) {
        n = 50;
        forn(i, n) a[i] = 3;
    } else {
        cin >> n;
        forn(i, n) cin >> a[i];
    }

    int ans = 0;
    d[1][a[0]] = 1;
    for (int ed = a[0]; ed < n; ++ed) {
        for (int beg = 0; beg <= ed; ++beg) {
            if (d[beg][ed] == 0) {
                continue;
            }
            int one = 0;
            int two = 0;
            for (int i = beg; i <= ed; ++i) {
                if (a[i] == 2) ++one;
                else ++two;
            }
            if (ed == n - 1) {
                ans = (ans + (LL)d[beg][ed] * e[one][two]) % MOD;
                continue;
            }
            int mx = n - 1 - ed;
            for (int oo = 0; oo <= one; ++oo) {
                for (int to = 0; to <= two; ++to) {
                    for (int tt = 0; to + tt <= two; ++tt) {
                        int cnt = oo + to + 2 * tt;
                        if (cnt > mx) {
                            continue;
                        }
                        int newOne = one - oo + to;
                        int newTwo = two - to - tt;
                        d[ed + 1][ed + cnt] = (d[ed + 1][ed + cnt] + (LL)d[beg][ed] * e[newOne][newTwo] % MOD *
                                               c[cnt][oo] % MOD * f[oo] % MOD *
                                               c[cnt - oo][to] % MOD * f[to] % MOD *
                                               f[tt * 2] % MOD * inv2[tt] % MOD *
                                               c[one][oo] % MOD * c[two][to] % MOD * c[two - to][tt]) % MOD;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}