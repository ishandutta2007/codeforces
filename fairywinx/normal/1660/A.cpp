#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0)
        cout << 1 << '\n';
    else
        cout << 2 * b + a + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}