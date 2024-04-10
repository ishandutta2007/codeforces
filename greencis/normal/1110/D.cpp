#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*set<vector<int>> st;
void dfs(vector<int> v) {
    if (st.count(v)) return;
    st.insert(v);
    for (int i = 1; i + 1 < (int)v.size(); ++i) {
        int cur = v[i - 1] + v[i + 1] - v[i];
        int prv = v[i];
        v[i] = cur;
        dfs(v);
        v[i] = prv;
    }
}*/

int n, m, cnt[1001005];
const int MAXC = 9;
int dp[2][MAXC + 1][MAXC + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    for (int i = 1; i <= m; ++i) {
        if (cnt[i] > MAXC) {
            int addon = (cnt[i] - MAXC + 2) / 3;
            ans += addon;
            cnt[i] -= addon * 3;
        }
    }

    int cur = 0;
    memset(dp[cur], -1, sizeof(dp[cur]));
    dp[cur][0][0] = 0;
    for (int i = 1; i <= m + 2; cur ^= 1, ++i) {
        memset(dp[cur ^ 1], -1, sizeof(dp[cur ^ 1]));
        for (int x = 0; x <= MAXC; ++x) {
            for (int y = 0; y <= MAXC; ++y) {
                if (dp[cur][x][y] < 0) continue;
                for (int z = 0; z <= cnt[i]; ++z) {
                    if (y + z > cnt[i - 1]) continue;
                    if (x + y + z > (i > 1 ? cnt[i - 2] : 0)) continue;
                    dp[cur ^ 1][y][z] = max(dp[cur ^ 1][y][z], dp[cur][x][y] + z + ((i > 1 ? cnt[i - 2] : 0) - x - y - z) / 3);
                }
            }
        }
    }

    int curans = 0;
    for (int i = 0; i <= MAXC; ++i)
        for (int j = 0; j <= MAXC; ++j)
            curans = max(curans, dp[cur][i][j]);
    cout << ans + curans << endl;

    /*vector<int> v{1, 3, 9, 27, 81, 243, 729};
    dfs(v);
    cerr << st.size() << endl;
    for (auto v : st) {
        for (int x : v) {
            int cur = x;
            for (int i = 0; i < v.size(); ++i) {
                char out = '0';
                if ((cur % 3 + 3) % 3 == 1) out = '+', --cur;
                else if ((cur % 3 + 3) % 3 == 2) out = '-', ++cur;
                cur /= 3;
                cout << out;
            }
            cout << "   ";
        }
        cout << endl;
    }*/
}