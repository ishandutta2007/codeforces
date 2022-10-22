#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    int c = k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; 
        c = __gcd(c, x);
    }   

    vector <int> ans;
    for (int i = 0; i < k; ++i) if (i % c == 0) ans.push_back(i);

    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' ';
    cout << '\n';

    return 0;
}