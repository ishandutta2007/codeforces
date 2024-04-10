#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (char ch : s) {
            if (ch == 'E') {
                ++cnt1;
            } else {
                ++cnt0;
            }
        }
        if (cnt0 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}