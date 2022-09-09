#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int c, d;
        cin >> c >> d;
        if ((c + d) & 1) cout << "-1\n";
        else if (c != d) cout << "2\n";
        else if (c == 0) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}