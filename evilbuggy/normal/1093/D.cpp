#include <bits/stdc++.h>
using namespace std;

const long long int mod = 998244353;

long long int modPow(long long int a, long long int b){
    long long int ans = 1, prod = a;
    while(b > 0){
        if(b&1)ans = (ans*prod)%mod;
        prod = (prod*prod)%mod;
        b >>= 1;
    }
    return ans;
}

vector<int> g[300005];
int n,m, vis[300005], n1, n2;
bool bprt;

void dfs(int v, int col){
    if(vis[v] != 0){
        if(vis[v] == col)return;
        bprt = false;
        return;
    }
    vis[v] = col;
    if(col == 1)n1++;
    else n2++;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        dfs(u, 3-col);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            vis[i] = 0;
        }
        int u,v;
        for(int i = 0; i < m; i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bprt = true;
        long long int ans = 1;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                n1 = 0;
                n2 = 0;
                dfs(i, 1);
                long long int tmp = modPow(2, n1) + modPow(2, n2);
                ans = (ans*tmp)%mod;
            }
        }
        if(!bprt){
            cout<<0<<endl;
        }else{
            cout<<ans<<endl;
        }
    }

}