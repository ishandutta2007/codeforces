#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    cout << max(0ll, n - 2 * m) << ' ';

    for (int i = n; i >= 0; --i) {
        int ost = n - i;
        if (ost * (ost - 1) / 2 >= m) {
            cout << i << '\n';
            exit(0);
        }   
    }

    return 0;   
}