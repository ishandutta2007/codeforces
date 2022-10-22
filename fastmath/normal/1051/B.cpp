#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, r;
    cin >> l >> r;    

    cout << "YES\n";
    for (int i = l; i < r; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }

    return 0;
}