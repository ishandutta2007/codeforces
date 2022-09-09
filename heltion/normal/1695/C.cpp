#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector<int>(m));
        vector L(n, vector<int>(m, INT_MAX)), R(n, vector<int>(m, INT_MIN));
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1) {
                cin >> a[i][j];
                if (i == 0 and j == 0)
                    L[i][j] = R[i][j] = 0;
                if (i) {
                    L[i][j] = min(L[i][j], L[i - 1][j]);
                    R[i][j] = max(R[i][j], R[i - 1][j]);
                }
                if (j) {
                    L[i][j] = min(L[i][j], L[i][j - 1]);
                    R[i][j] = max(R[i][j], R[i][j - 1]);
                }
                L[i][j] += a[i][j];
                R[i][j] += a[i][j];
            }
        //cout << L[n - 1][m - 1] << " " << R[n - 1][m - 1] << "\n";
        if (L[n - 1][m - 1] % 2 or L[n - 1][m - 1] > 0 or R[n - 1][m - 1] < 0)
            cout << "NO\n";
        else cout << "YES\n";
    }
}