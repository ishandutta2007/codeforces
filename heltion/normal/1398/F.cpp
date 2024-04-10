#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 2;
char s[maxn];
int r[maxn], f[2][maxn], g[maxn];
vector<int> G[maxn];
int gr(int u){
    return u == r[u] ? u : r[u] = gr(r[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n >> (s + 1);
    for(int i = n; i >= 1; i -= 1){
        if(s[i] == '?'){
            f[0][i] = f[0][i + 1] + 1;
            f[1][i] = f[1][i + 1] + 1;
        }
        else{
            int u = s[i] - '0', v = u ^ 1;
            f[u][i] = f[u][i + 1] + 1;
            f[v][i] = 0;
        }
        g[i] = max(f[0][i], f[1][i]);
        G[g[i]].push_back(i);
        r[i] = i;
    }
    r[n + 1] = n + 1;
    for(int i = 1; i <= n; i += 1){
        int L = 1, ans = 0;
        while(L <= n){
            int R = gr(L);
            if(R > n) break;
            L = R + i;
            ans += 1;
        }
        for(auto p : G[i]) r[p] = p + 1;
        cout << ans << " ";
    }
    return 0;
}