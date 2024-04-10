#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
const int INF = 1e9 + 7;

int a[MAXN], b[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];    
    
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                ans = min(ans, a[i]);
            }
            else {
                int x = min(a[i], b[j]);
                int y = max(a[i], b[j]);
                ans = min(ans, x * 10 + y);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}