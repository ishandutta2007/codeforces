#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        vector<int> sz(4);
        vector<vector<int>> arr(4);
        for (int i = 0; i < 4; ++i) {
            cin >> sz[i];
            arr[i].resize(sz[i]);
            for (int j = 0; j < sz[i]; ++j) {
                cin >> arr[i][j];
            }
        }

        int max_diff_x = 0, max_diff_y = 0;
        for (int i : {0, 1}) {
            max_diff_x = max(max_diff_x, arr[i].back() - arr[i][0]);
        }
        for (int i : {2, 3}) {
            max_diff_y = max(max_diff_y, arr[i].back() - arr[i][0]);
        }
        cout << max(max_diff_x * 1ll * h, max_diff_y * 1ll * w) << '\n';
    }
    return 0;
}