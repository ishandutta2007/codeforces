#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] + a[1] == a[2] || (a[0] == a[1] && a[2] % 2 == 0) || (a[1] == a[2] && a[0] % 2 == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}