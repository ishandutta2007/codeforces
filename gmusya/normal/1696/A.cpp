#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int ans = (a[0] | z);
        for (int& x : a) {
            ans = max(ans, x | z);
        }
        cout << ans << '\n';
    }
    return 0;
}