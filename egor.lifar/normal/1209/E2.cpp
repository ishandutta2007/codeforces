/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 2222;


int n, m;
int a[13][MAXN];
int dp[14][4400];
int val[14];
int op[4400];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<pair<int, int> > st;
        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                chkmax(cur, a[j][i]);
            }
            st.pb({cur, i});
        }
        sort(all(st));
        reverse(all(st));
        for (int i = 0; i <= min(sz(st), n); i++) {
            for (int j = 0; j < (1 << n); j++) {
                dp[i][j] = -1e9;
            }
        }
        dp[0][(1 << n) - 1] = 0;
        for (int i = 0; i < min(sz(st), n); i++) {
            for (int cur = 0; cur < (1 << n); cur++) {
                op[cur] = 0;
                for (int j = 0; j < n; j++) {
                    int res = 0;
                    for (int k = 0; k < n; k++) {
                        if (cur & (1 << k)) {
                            res += a[(j + k) % n][st[i].second];
                        }
                    }
                    chkmax(op[cur], res);
                }
            }
            for (int cur = 0; cur < (1 << n); cur++) {
                for (int fk = cur; fk; fk = (fk - 1) & cur) {
                    chkmax(dp[i + 1][fk], dp[i][cur] + op[(cur ^ fk)]);
                }
                chkmax(dp[i + 1][0], dp[i][cur] + op[cur]);
            }
        }
        cout << dp[min(sz(st), n)][0] << '\n';
    }
    return 0; 
}