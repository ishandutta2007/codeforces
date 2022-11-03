#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 6;
const int A = 21;

/*

*/

int a[A][A];

int dp[1 << A];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int t = 1;
//    cin >> t;

//    while(t--)
//        solve();

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    for(int i = 1; i < n; i++) {
        int x = s[i - 1] - 'a';
        int y = s[i] - 'a';

        a[x][y]++;
        a[y][x]++;
    }

    dp[0] = 0;
    for(int i = 1; i < (1 << m); i++) {
        dp[i] = INF;
    }

    for(int mask = 0; mask < (1 << m) - 1; mask++) {
        int s = 0;
        for(int i = 0; i < m; i++) if(((mask >> i) & 1) == 1) {
            for(int j = 0; j < m; j++) if(((mask >> j) & 1) == 0)
                s += a[i][j];
        }
        for(int x = 0; x < m; x++)
            if(((mask >> x) & 1) == 0) {
                int nmask = (mask | (1 << x));
                int res = dp[mask] + s;
                dp[nmask] = min(dp[nmask], res);

//                for(int i = 0; i < m; i++)
//                    if(((mask >> i) & 1) == 1)
//                        res += a[x][i];
            }
    }

    cout << dp[(1 << m) - 1];
}