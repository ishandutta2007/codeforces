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
        vector<char> str(n);
        for (int i = 0; i < n; ++i) {
            cin >> str[i];
        }
        int ans = n + 1;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int cur_ans = 0;
            int l = 0, r = n - 1;
            while (l < r) {
                if (str[l] == str[r]) {
                    ++l;
                    --r;
                    continue;
                }
                if (str[l] == ch) {
                    ++l;
                    ++cur_ans;
                    continue;
                }
                if (str[r] == ch) {
                    --r;
                    ++cur_ans;
                    continue;
                } else {
                    cur_ans = n + 1;
                    break;
                }
            }
            ans = min(ans, cur_ans);
        }
        if (ans == n + 1) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}