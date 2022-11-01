#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans1 = (c >= a ? c - a : 2 * n - (a + c));
        int ans2 = (d >= b ? d - b : 2 * m - (b + d));
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}