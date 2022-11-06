#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> v(20, -1);
    for(int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        v[d] = max(v[d], b);
    }
    int ans = 0;
    for(int i = 1; i <= 10; i++) {
        if(v[i] == -1) {
            cout << "MOREPROBLEMS" << endl;
            return;
        }
        ans += v[i];
    }
    cout << ans << endl;
}

 main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}