#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int m;
        cin >> m;
        vector a(2, vector<int>(m));
        for (int i = 0; i < 2; i += 1)
            for (int j = 0; j < m; j += 1) {
                cin >> a[i][j];
                if (a[i][j]) a[i][j] += 1;
            }
        vector b(2, vector<int>(m)), c(2, vector<int>(m));
        for (int i = 0; i < 2; i += 1)
            for (int j = m - 1; j >= 0; j -= 1) {
                b[i][j] = a[i][j] + j;
                c[i][j] = a[i][j] - j;
                if (j + 1 < m) {
                    b[i][j] = max(b[i][j], b[i][j + 1]);
                    c[i][j] = max(c[i][j], c[i][j + 1]);
                }
            }
        int ans = INT_MAX, pans = -1;
        for (int i = 0; i + 1 < m; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                int k = (i & 1) ^ j;
                pans = max(pans + 1, a[k][i]);
                ans = min(ans, max({pans + 2 * m - 1 - 2 * i - j, c[k][i + 1] + 2 * m - 1 - i - j, b[k ^ 1][i] - i - j}));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}