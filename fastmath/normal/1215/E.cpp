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
const int N = 4e5 + 7, C = 20;
vector <int> p[C];
int cost[C][C];
int a[N];
int dp[1 << C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        p[a[i]].app(i);
    }
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            int ptr = 0;
            for (int e : p[j]) {
                while (ptr < p[i].size() && p[i][ptr] < e) ++ptr;
                cost[i][j] += ptr;
            }   
        }   
    }
    const int INF = 1e18 + 7;
    for (int i = 1; i < (1 << C); ++i) dp[i] = INF;
    for (int mask = 0; mask < (1 << C); ++mask) {
        for (int i = 0; i < C; ++i) {
            if (!((mask >> i) & 1)) {
                int add = 0;
                for (int j = 0; j < C; ++j) 
                    if ((mask >> j) & 1)
                        add += cost[i][j];
                dp[mask + (1 << i)] = min(dp[mask + (1 << i)], dp[mask] + add);
            }   
        }   
    }
    cout << dp[(1 << C) - 1] << '\n';
}