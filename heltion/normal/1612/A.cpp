#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1)
            cout << "-1 -1\n";
        else if (x & 1)
            cout << x / 2 << " " << (y + 1) / 2 << "\n";
        else cout << x / 2 << " " << y / 2 << "\n";
    }
    return 0;
}