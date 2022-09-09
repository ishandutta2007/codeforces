#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
constexpr int maxn = 4000 + 1;
vector<int> G[maxn];
int cnt;
vector<int> cyc;
int vis[maxn];
void DFS(int u, int par){
    vis[u] = 1;
    cnt += 1;
    for(int v : G[u]) if(v != par and v != 1) DFS(v, u);
}
LL DP[maxn * 2];
LL dp[maxn * 2];
void add(LL& x, LL y){
    x += y;
    if(x >= mod) x -= mod;
}
void sub(LL& x, LL y){
    x -= y;
    if(x < 0) x += mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i = 1, x, y; i <= M; i += 1){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int v : G[1]) if(not vis[v]){
        cnt = 1;
        DFS(v, 1);
        cyc.push_back(cnt);
    }
    DP[0] = 1;
    for(int x : cyc) for(int j = 2 * M; j >= 2 * x; j -= 1) add(DP[j], DP[j - 2 * x]);
    LL ans = DP[M] % mod;
    for(int x : cyc){
        for(int j = 0; j <= 2 * M; j += 1){
            if(j >= x * 2) sub(DP[j], DP[j - 2 * x]);
        }
        for(int j = 0; j <= 2 * M; j += 1){
            //cout << x << " " << j - M + x << " " << DP[j] << "\n";
            if(abs(j - M + x) == abs(x - 1)){
                add(ans, DP[j]);
                add(ans, DP[j]);
            }
        }
        for(int j = 2 * M; j >= 0; j -= 1){
            if(j >= x * 2) add(DP[j], DP[j - 2 * x]);
        }
    }
    dp[0] = 1;
    for(int x : cyc) for(int j = 2 * M; j >= 0; j -= 1){
        if(j >= x) add(dp[j], dp[j - x]);
        if(j >= x * 2) add(dp[j], dp[j - 2 * x]);
    }
    for(int x : cyc){
        for(int j = 0; j <= 2 * M; j += 1){
            if(j >= x) sub(dp[j], dp[j - x]);
            if(j >= x * 2) sub(dp[j], dp[j - 2 * x]);
        }
        for(int j = 0; j <= 2 * M; j += 1){
            //cout << x << " " << j - M + x << " " << dp[j] << "\n";
            if(abs(j - M + x) <= x - 2){
                add(ans, dp[j]);
                add(ans, dp[j]);
            }
        }
        for(int j = 2 * M; j >= 0; j -= 1){
            if(j >= x) add(dp[j], dp[j - x]);
            if(j >= x * 2) add(dp[j], dp[j - 2 * x]);
        }
    }
    cout << ans;
    return 0;
}