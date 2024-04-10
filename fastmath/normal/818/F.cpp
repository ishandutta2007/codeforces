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
        int n;
        cin >> n;
        int ans = 0;
 
        int l = 0, r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            int sz = n - m;
            int e = sz * (sz - 1) / 2;
            if (e > m)
                l = m;
            else
                r = m; 
        }   
 
        for (int i = l; i < n && i <= r; ++i) {
            int sz = n - i;
            int e = sz * (sz - 1) / 2;
            ans = max(ans, i + min(i, e));
        }
        cout << ans << '\n';
    }   
 
}