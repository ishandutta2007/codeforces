#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
int max(vector <int> a) {
    int ans = 0;
    for (int e : a) ans = max(ans, e);
    return ans;
}   
bool comp(vector <int> a, vector <int> b) {
    return max(a) > max(b);
}   
int a[12][2000];
vector <int> d[2000];
int dp[13][1 << 12];
int prec[13][1 << 12];
void solve() {
    for (int i = 0; i < 2000; ++i) d[i].clear();
    for (int i = 0; i < 13; ++i) for (int j = 0; j < (1 << 12); ++j) dp[i][j] = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) d[j].app(a[i][j]);
    sort(d, d + m, comp);        
    for (int i = 0; i < min(n, m); ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            prec[i][mask] = 0;
            for (int sh = 0; sh < n; ++sh) {
                int nn = 0;
                for (int j = 0; j < n; ++j) {
                    if ((mask >> j) & 1) nn += d[i][(j + sh) % n];
                }   
                prec[i][mask] = max(prec[i][mask], nn);
            }   
        }   
    }   
    for (int i = 0; i < min(n, m); ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            dp[i + 1][mask] = dp[i][mask];
            for (int add = mask; add; add = (add - 1) & mask) {
                dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask - add] + prec[i][add]);
            }   
        }   
    }   
    cout << dp[min(n, m)][(1 << n) - 1] << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}