#include <bits/stdc++.h>
using namespace std;
int n, m, tag, a[200010], b[200010], q;
set < pair < int, int > > st;
int maxans;
vector < int > dp[200010];
inline void chkmax(int &a, int b) {
    if (a < b) a = b;
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    if (n < m) tag = 1, swap(n, m);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", a + i, b + i);
        if (tag) swap(a[i], b[i]);
        st.insert({a[i], b[i]});
    }
    maxans = n / m + 32;
    for (int i = 1; i <= m; i++) dp[i] = vector < int > (maxans, -1);
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < maxans - 1; j++) if (dp[i][j] > 0) {
            int to = i + dp[i][j] + st.count({dp[i][j], i});
            if (to <= 0) continue;
            chkmax(dp[i][j + 1], min(to, n));
            chkmax(dp[min(to, m)][j + 1], dp[i][j]);
        }
    }
    for (int i = 0; i < maxans; i++) if (dp[m][i] == n) return cout << i << endl, 0;
    cout << maxans << endl;
}