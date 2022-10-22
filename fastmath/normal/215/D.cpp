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
const int N = 1e6 + 7;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int q, m;
    cin >> q >> m;
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int t, T, x, cost;
        cin >> t >> T >> x >> cost;
        int mx = max(0ll, T - t);
        if (mx == 0) {
            ans += cost + x * m;
            continue;
        }   
        int add = (m + mx - 1) / mx * cost;
        add = min(add, cost + x * m);
        add = min(add, cost * (1 + m / mx) + x * (m % mx));
        ans += add;    
    }   
    cout << ans << endl;
}