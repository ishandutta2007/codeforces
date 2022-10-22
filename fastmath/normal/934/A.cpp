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

    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int ans = 2e18;    
    for (int i = 0; i < n; ++i) {
        int mx = -2e18;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                for (int k = 0; k < m; ++k)
                    mx = max(mx, a[j] * b[k]); 
            }   
        }   
        ans = min(ans, mx);
    }   
    cout << ans << endl;
}