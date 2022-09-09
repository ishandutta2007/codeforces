#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        if (n & 1) cout << 1 << " ";
        for (int i = n & 1 ? 2 : 1; i <= n; i += 2)
            cout << i + 1 << " " << i << " ";
        cout << "\n";
    }
}