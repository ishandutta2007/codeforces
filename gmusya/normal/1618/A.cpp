#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(7);
        for (int i = 0; i < 7; ++i) {
            cin >> a[i];
        }
        cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[0] - a[1] << '\n';
    }
    return 0;
}