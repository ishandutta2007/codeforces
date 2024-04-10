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
const int N = 2e5 + 7;
int a[N], p[N], ans[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];

    for (int i = 1; i <= min(n, m); ++i) {
        ans[i] = p[i];
    }       
    for (int i = min(n, m) + 1; i <= n; ++i) {
        ans[i] = p[i] + ans[i - m];
    }   

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}