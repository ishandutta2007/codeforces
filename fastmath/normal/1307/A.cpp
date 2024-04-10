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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector <int> a(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            if (i == 0)
                ans += a[i];
            else {
                int mx = min(d / i, a[i]);
                d -= mx * i;
                ans += mx;
            }   
        }
        cout << ans << '\n';
    }   
}