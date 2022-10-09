#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    pair<int, int> mx = {0, -228};
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > mx.first) {
            mx.second = mx.first;
            mx.first = a;
        } else if (a > mx.second) {
            mx.second = a;
        }
    }
    if (mx.second + 1 < mx.first && mx.first != 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}