#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k * 2 >= n + 2 ) {
            cout << -1 << '\n';
            continue;
        }
        vector<vector<char>> ans(n, vector<char>(n, '.'));
        for (int i = 0; i < k; ++i) {
            ans[i * 2][i * 2] = 'R';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}