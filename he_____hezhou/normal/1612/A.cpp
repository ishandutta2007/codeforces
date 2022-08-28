#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1) cout << -1 << ' ' << -1 << endl;
        else if (x % 2 == 0) cout << x / 2 << ' ' << y / 2 << endl;
        else cout << x / 2 << ' ' << (y + 1) / 2 << endl;
    }
}