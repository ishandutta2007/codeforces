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
const int N = 1007;
int lcp[N][N];
int n, m, k;
string s;
bool comp(ii a, ii b) {
    int l = lcp[a.f][b.f];
    l = min(l, a.s);
    l = min(l, b.s);
    if (l < min(a.s, b.s)) 
        return s[a.f + l] < s[b.f + l];
    else 
        return a.s == l && a.s < b.s;
}   
const int INF = 2e18 + 7;
int dp[N][N], sum[N][N];
int get(ii key) {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = sum[i][j] = 0;
    dp[n][0] = sum[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int l = n + 1;
        for (int add = 1; i + add <= n; ++add) 
            if (!comp(mp(i, add), key)) {
                l = i + add;
                break;
            }
        for (int j = 0; j <= m; ++j) {
            if (j)
                dp[i][j] = sum[l][j - 1];
            sum[i][j] = min(dp[i][j] + sum[i + 1][j], INF);
        }   
    }
    return dp[0][m];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    cin >> s;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] != s[j]) {
                lcp[i][j] = 0;
            }   
            else if (i + 1 < n && j + 1 < n) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
            else {
                lcp[i][j] = 1;
            }   
        }   
    }   

    vector <ii> a;
    for (int i = 0; i < n; ++i) 
        for (int len = 1; i + len - 1 < n; ++len)
            a.app(mp(i, len));
    sort(all(a), comp);
    
    int l = -1, r = a.size();
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (k <= get(a[m]))
            l = m;
        else
            r = m;
    }   
        
    cout << s.substr(a[l].f, a[l].s) << endl;
}