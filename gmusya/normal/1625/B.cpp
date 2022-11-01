#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            arr[a[i]].push_back(i);
        }
        int ans = -1;
        for (auto& now : arr) {
            auto& tmp = now.second;
            for (int i = 0; i + 1 < (int) tmp.size(); ++i) {
                ans = max(ans, n - (tmp[i + 1] - tmp[i]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}