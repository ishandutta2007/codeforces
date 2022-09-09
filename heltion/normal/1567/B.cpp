#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b;
        cin >> a >> b;
        int c = a & 1 ? (a - 1) ^ (a % 4 == 3) : a % 4 == 2;
        if (c == b) cout << a;
        else if ((c ^ a) == b) cout << a + 2;
        else cout << a + 1;
        cout << "\n";
    }
    return 0;
}