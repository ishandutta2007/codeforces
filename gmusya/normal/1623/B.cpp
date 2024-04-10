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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        vector<bool> used(n + 1);
        sort(a.begin(), a.end(), [&](auto& i, auto& j) {
            return i.second - i.first < j.second - j.first;
        });
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << " " << a[i].second << " ";
            int x = a[i].first;
            while (used[x]) {
                ++x;
            }
            used[x] = true;
            cout << x << "\n";
        }
        cout << "\n";
    }
    return 0;
}