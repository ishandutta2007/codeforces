#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2400;
struct Tree{
    int n;
    int Leaf[maxn];
    int p[maxn];
    int d[maxn][maxn];
    vector<int> G[maxn];
    void fd(int u){
        queue<int> q;
        fill(d[u] + 1, d[u] + n + 1, n);
        d[u][u] = 0;
        q.push(u);
        while(not q.empty()){
            int v = q.front();
            q.pop();
            for(int w : G[v]) if(d[u][w] == n){
                d[u][w] = d[u][v] + 1;
                q.push(w);
            }
        }
    }
    void read(int n){
        cin >> this->n;
        for(int i = 2; i <= this->n; i += 1){
            cin >> p[i];
            G[i].push_back(p[i]);
            G[p[i]].push_back(i);
        }
        for(int i = 1; i <= this->n; i += 1) fd(i);
        for(int i = 1; i <= n; i += 1) cin >> Leaf[i];
    }
    int dis(int u, int v){
        if(v == 0) return d[Leaf[u]][1];
        return (d[Leaf[u]][Leaf[v]] + d[Leaf[u]][1] - d[Leaf[v]][1]) / 2;
    }
}T[2];
int dp[maxn][maxn][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    T[0].read(n);
    T[1].read(n);
    dp[1][0][0] = T[0].dis(1, 0);
    dp[1][0][1] = T[1].dis(1, 0);
    for(int i = 2; i <= n; i += 1)
        for(int j = 0; j < i; j += 1)
            for(int t = 0; t < 2; t += 1){
                if(i - j >= 2)  dp[i][j][t] = dp[i - 1][j][t] + T[t].dis(i, i - 1);
                if(i - j == 1){
                    dp[i][i - 1][t] = INT_MAX;
                    for(int k = 0; k < i - 1; k += 1) dp[i][i - 1][t] = min(dp[i][i - 1][t], dp[i - 1][k][t ^ 1] + T[t].dis(i, k));
                }
            }
    int ans = INT_MAX;
    for(int j = 0; j < n; j += 1){
        ans = min(ans, dp[n][j][0]);
        ans = min(ans, dp[n][j][1]);
    }
    cout << T[0].n - 1 + T[1].n - 1 - ans;
}