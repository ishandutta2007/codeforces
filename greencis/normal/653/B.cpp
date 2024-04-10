#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, q, dp[9][999999], res;
char s[99][9], t[99][9];

int dfs(int len, int x) {
    if (len == 1)
        return x == 0;
    if (!dp[len][x]) {
        int ans = 0;
        int xxx = x;
        int cur1 = xxx % 6; xxx /= 6;
        int cur2 = xxx % 6; xxx /= 6;
        for (int i = 0; i < q; ++i) {
            if (s[i][0] - 'a' == cur1 && s[i][1] - 'a' == cur2) {
                ans |= dfs(len - 1, xxx * 6 + t[i][0] - 'a');
            }
        }
        dp[len][x] = ans + 1;
    }
    return dp[len][x] - 1;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        cin >> s[i] >> t[i];
    }

    int mx = 1;
    for (int i = 0; i < n; ++i) mx *= 6;
    for (int i = mx; i--; ) {
        res += dfs(n, i);
    }
    cout << res;

    return 0;
}