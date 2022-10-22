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
const int N = 1e6 + 7;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }   
    vector <ll> pri;
    for (ll d = 2; d * d <= sum; ++d) {
        if (sum % d == 0) {
            pri.app(d);
            while (sum % d == 0)
                sum /= d;
        }   
    }                  
    if (sum > 1) pri.app(sum);
    const ll INF = 2e18 + 7;
    ll ans = INF;
    for (int p : pri) {
        for (int i = 0; i < n; ++i)
            b[i] = a[i];
        ll nn = 0;
        for (int i = 0; i + 1 < n; ++i) {
            b[i] %= p;
            nn += min(b[i], p - b[i]);
            b[i + 1] += b[i];
        }   
        ans = min(ans, nn);
    }   
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}