#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

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
        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n / 2; ++i) {
            b.push_back(a[i]);
            b.push_back(a[i + n / 2]);
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            int prev = (i == 0 ? n - 1 : i - 1);
            int nxt = (i == n - 1 ? 0 : i + 1);
            if (!((b[i] > b[prev] && b[i] > b[nxt]) || (b[i] < b[prev] && b[i] < b[nxt]))) {
                good = false;
            }
        }
        if (good) {
            cout << "YES\n";
            for (auto& now : b) {
                cout << now << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}