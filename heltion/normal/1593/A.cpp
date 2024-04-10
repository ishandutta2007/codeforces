#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    for (cin >> T; T; T -= 1) {
        int a, b, c;
        cin >> a >> b >> c;
        int m = max({a, b, c});
        cout << m + (m == b or m == c) - a<< " "
            << m + (m == a or m == c) - b << " "
            << m + (m == a or m == b) - c << "\n";
    }
    return 0;
}