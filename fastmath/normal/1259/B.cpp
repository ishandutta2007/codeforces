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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        map <int, int> d;
        while (n--) {
            int x; cin >> x;
            int pw = 0;
            while (x % 2 == 0) {
                ++pw;
                x >>= 1;
            }   
            d[x] = max(d[x], pw);
        }   
        int ans = 0;
        for (auto e : d) 
            ans += e.s;
        cout << ans << '\n';
    }   
}