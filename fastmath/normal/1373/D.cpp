#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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

        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        const int INF = 1e18;

        //vector <int> pref(n+1);
        vector <int> mn(2, INF);
        mn[1] = 0;

        int d = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                cur += a[i];
            }   
            else {
                cur -= a[i];
            }   
            d = max(d, cur - mn[i&1]);
            mn[i&1] = min(mn[i&1], cur);
        }

        int ans = 0;
        for (int i = 0; i < n; i += 2)
            ans += a[i];

        cout << ans + d << endl;
    }   

}