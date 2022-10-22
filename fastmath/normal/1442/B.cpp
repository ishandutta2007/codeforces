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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        vector <int> b(k);
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
        }           
        reverse(all(b));
        vector <bool> used(n + 2);
        used[0] = 1;
        used[n + 1] = 1;
        int ans = 1;
        const int MOD = 998244353;
        for (auto x : b) {
            int i = pos[x];
            used[i] = 1;
            ans *= (2 - used[i - 1] - used[i + 1]);                                          
            ans %= MOD;
        }   
        cout << ans << endl;        
    }   
}