#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n);
        for (LL& x : a) cin >> x;
        LL ans = 0;
        for (int i = 1; i < n; i += 1) ans = max(ans, a[i - 1] * a[i]);
        cout << ans << "\n";
    }
    return 0;
}