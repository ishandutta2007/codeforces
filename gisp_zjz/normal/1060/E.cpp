#include<bits/stdc++.h>
#define maxn 234560

using namespace std;
typedef long long ll;
ll a[maxn],sz[maxn],ans,n,dep[maxn],s;
vector<int>h[maxn];

void dfs(int u,int fa){
    sz[u]=1;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        if (v==fa) continue;
        dep[v]=dep[u]^1;
        dfs(v,u); sz[u]+=sz[v];
    }
    if (u!=1) ans+=sz[u]*(n-sz[u]);
}

int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dfs(1,0); s=0;
    for (int i=1;i<=n;i++) if (dep[i]) s++;
    ans+=s*(n-s);
    cout << ans/2 << endl;
}