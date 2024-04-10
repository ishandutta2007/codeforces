#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }           

    for (int i = 0; i < n; ++i) {
        int ans = 1;
        for (int j = 0; j < n; ++j) {
            ans += (a[i] < a[j]);
        }   
        cout << ans << ' ';
    }   
    cout << '\n';

    return 0;
}