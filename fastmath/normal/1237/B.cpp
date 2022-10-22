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
const int N = 1e5 + 7;
int a[N], b[N], p[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) { cin >> b[i]; p[b[i]] = i; }
    for (int i = 1; i <= n; ++i) a[i] = p[a[i]];
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += mx > a[i];
        mx = max(mx, a[i]);
    }   
    cout << ans << '\n';
}