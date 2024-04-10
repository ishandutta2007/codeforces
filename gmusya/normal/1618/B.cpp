#include <iostream>
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
        vector<string> arr(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            cin >> arr[i];
        }
        string ans = arr[0];
        for (int i = 1; i < n - 2; ++i) {
            if (arr[i][0] == ans.back()) {
                ans += arr[i][1];
            } else {
                ans += arr[i];
            }
        }
        if (ans.size() < n) {
            ans += 'b';
        }
        cout << ans << '\n';
    }
    return 0;
}