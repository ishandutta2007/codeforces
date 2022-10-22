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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int l = (i + n - 1) % n;
        sum += max(0ll, a[i] - b[l]);
    }   

    int ans = 1e18 + 7;
    for (int i = 0; i < n; ++i) {
        int l = (i + n - 1) % n;
        ans = min(ans, sum - max(0ll, a[i] - b[l]) + a[i]);
    }   
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