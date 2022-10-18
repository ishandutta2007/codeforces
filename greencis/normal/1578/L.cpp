#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(0, max(b, c) + 1 - a) << ' ';
        cout << max(0, max(c, a) + 1 - b) << ' ';
        cout << max(0, max(a, b) + 1 - c) << '\n';
    }
}