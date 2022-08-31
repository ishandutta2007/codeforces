#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 5001;
int a[maxn][3];
int sol[3], can[3];
int t[3], tob[3];
int dp[2][90][90][90];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;

    forn(i, n) forn(j, 3) {
        cin >> a[i][j];
        sol[j] += a[i][j] != 0;
        can[j] += a[i][j] < 0;
    }
    if (can[0] + can[1] + can[2] >= 90) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = 1e9;
    for (t[0] = 0; t[0] < 6; ++t[0]) {
        for (t[1] = 0; t[1] < 6; ++t[1]) {
            for (t[2] = 0; t[2] < 6; ++t[2]) {
                bool ok = true;
                forn(i, 3) {
                    tob[i] = min(can[i], max(0, (t[i] == 5 ? (int)1e9 : sol[i] - (n >> (t[i] + 1)) - 1)));
                    int z = (sol[i] - tob[i]) << (t[i] + 1);
                    ok &= ((t[i] == 5 || n < z) && z <= 2 * n);
                }
                if (!ok) continue;
                int myB = 0;
                forn(i, 3) {
                    myB += 100 * tob[i];
                    if (a[0][i]) myB += 2 * (t[i] + 1) * (250 - a[0][i]);
                }
                forn(i, tob[0] + 1) forn(j, tob[1] + 1) forn(k, tob[2] + 1) dp[0][i][j][k] = 1e9;
                dp[0][tob[0]][tob[1]][tob[2]] = 0;
                int twin = 0;
                for1(p, n - 1) {
                    bool ist = true;
                    forn(m, 3) ist &= a[p][m] >= 0;
                    if (ist) {
                        int hisb = 0;
                        forn(m, 3) {
                            if (a[p][m]) hisb += 2 * (t[m] + 1) * (250 - abs(a[p][m]));
                        }
                        if (hisb > myB) ++twin;
                        continue;
                    }
                    forn(i, tob[0] + 1) forn(j, tob[1] + 1) forn(k, tob[2] + 1) dp[1][i][j][k] = 1e9;
                    forn(i, tob[0] + 1) forn(j, tob[1] + 1) forn(k, tob[2] + 1) {
                        forn(ti, 2) forn(tj, 2) forn(tk, 2) {
                            if (ti && (!i || a[p][0] >= 0)) continue;
                            if (tj && (!j || a[p][1] >= 0)) continue;
                            if (tk && (!k || a[p][2] >= 0)) continue;
                            int hisB = 0;
                            if (a[p][0] && !ti) hisB += 2 * (t[0] + 1) * (250 - abs(a[p][0]));
                            if (a[p][1] && !tj) hisB += 2 * (t[1] + 1) * (250 - abs(a[p][1]));
                            if (a[p][2] && !tk) hisB += 2 * (t[2] + 1) * (250 - abs(a[p][2]));
                            uin(dp[1][i - ti][j - tj][k - tk], dp[0][i][j][k] + (hisB > myB));
                        }
                    }
                    forn(i, tob[0] + 1) forn(j, tob[1] + 1) forn(k, tob[2] + 1) dp[0][i][j][k] = dp[1][i][j][k];
                }
//                cerr << t[0] << ' ' << t[1] << ' ' << t[2] << ' ' << tob[0] << ' ' << tob[1] << ' ' << tob[2] << ' ' << myB << ' ' << twin + dp[0][0][0][0] + 1 << '\n';
                uin(ans, twin + dp[0][0][0][0]);
            }
        }
    }                                        
    cout << ans + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}