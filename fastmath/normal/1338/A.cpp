#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
void solve() {
    int n;
    cin >> n;

    int mx = -1e18;

    int add = 0;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        add = max(add, mx - a[i]);
    }   

    int ans = 0;
    while ((1ll << ans) <= add)
        ++ans;
    cout << ans << endl;
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}