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
#define debug(x) std::cout << #x << ": " << x << '\n';
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
        int n, k, z;
        cin >> n >> k >> z;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector <int> pref(n), sum(n+1);
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + a[i];
        for (int i = 0; i + 1 < n; ++i)
            pref[i + 1] = max(pref[i], a[i] + a[i + 1]);

        int ans = 0;                
        for (int en = k & 1; en <= k; ++en) {
            int l = (k - en) / 2;
            
            if (l <= z) {
                ans = max(ans, sum[en+1] + pref[en+1] * l);
            }   

        }   
        cout << ans << endl;
                    
    }   

}