#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch;
                cin >> ch;
                if (ch == '0') {
                    ++a;
                } else {
                    ++b;
                }
            }
        }
        int ans = 1;
        for (int x = 0; x < b; ++x) {
            ans *= 2;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        if (!a) {
            --ans;
            if (ans < 0) {
                ans += MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}