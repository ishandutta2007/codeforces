#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> v;
    int c = 0;
    for (int i = n - 1; i; --i) {
        c += a[i];
        v.app(c);
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i];
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    for (int i = 0; i < k - 1; ++i) ans += v[i];
    cout << ans << '\n';
}