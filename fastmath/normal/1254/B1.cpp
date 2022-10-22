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
const int N = 1e5 + 7;
bool a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    vector <int> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];    
        if (a[i]) 
            p.app(i);
    }
    vector <int> pri;
    int sum = p.size();
    for (int d = 2; d * d <= n; ++d)
        if (sum % d == 0) {
            pri.app(d);
            while (sum % d == 0) sum /= d;
        }   
    if (sum > 1) pri.app(sum);
    const int INF = 1e18 + 7;
    int ans = INF;
    for (int e : pri) {
        int nn = 0;
        for (int i = 0; i * e < p.size(); ++i) {
            vector <int> t;
            for (int j = 0; j < e; ++j) 
                t.app(p[i * e + j]);
            int mid = t[e >> 1];
            for (int e : t)
                nn += abs(mid - e);
        }   
        ans = min(ans, nn);
    }   
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}