#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    if (k % 2) {
        int ans = k / 2;
        if (n <= k / 2) ans = 0;
        else if (n < k - 1) ans -= (k - 1) - n;
        cout << ans << '\n';    
    }
    else {
        int ans = k / 2 - 1;
        if (n <= k / 2) ans = 0;
        else if (n < k - 1) ans -= (k - 1) - n;
        cout << ans << '\n';   
    }

    return 0;
}