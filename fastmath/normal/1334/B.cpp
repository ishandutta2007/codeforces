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
#define double long double
void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    vector <int> pref(n + 1), post(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        post[i] = post[i + 1] + a[i];
    for (int ans = n; ans >= 0; --ans) {
        if (post[n - ans] >= x * ans) {
            cout << ans << endl;
            return;
        }   
    }                        
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
    while (t--) {
        solve();
    }   
}