#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

string s, t;
int go[26][100005];
int pi[100105];
vector< vector<int> > dp;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            ++j;
        pi[i] = j;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i && t[i] - 'a' != j)
                go[j][i] = go[j][pi[i - 1]];
            else
                go[j][i] = i + (t[i] - 'a' == j);
        }
    }

    dp = vector< vector<int> >(n + 1, vector<int>(m + 1, -1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int L = s[i] - 'a', R = s[i] - 'a';
            if (s[i] == '?')
                L = 0, R = 25;
            for (; L <= R; ++L) {
                int nxt = go[L][j];
                if (nxt == m)
                    dp[i + 1][pi[m - 1]] = max(dp[i + 1][pi[m - 1]], dp[i][j] + 1);
                else
                    dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}