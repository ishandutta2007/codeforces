#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        if (n & 1) {
            cout << "NO\n";
        } else {
            bool flag = true;
            for (int i = 0; i < n / 2; ++i) {
                if (s[i] != s[i + n / 2]) {
                    flag = false;
                }
            }
            if (flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}