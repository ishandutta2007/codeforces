#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        LL n;
        cin >> n;
        if ((n & 1) or n == 2) cout << "-1\n";
        else cout << n / 6 + (n % 6 != 0) << " " << n / 4 << "\n";
    }
}