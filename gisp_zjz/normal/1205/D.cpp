#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int sz[1005],n,p,q,m,color[1005],dep[1005],pp,qq;
vector <int> h[1005];
void dfs(int u,int fa){
    sz[u]=1;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u); sz[u]+=sz[v];
    }
}
void dfs2(int u,int fa,int col){
    if (col==1) pp++,dep[u]=pp;
    else qq+=(p+1),dep[u]=qq;
    printf("%d %d %d\n",fa,u,dep[u]-dep[fa]);
    for (auto v:h[u]) if (v!=fa) dfs2(v,u,col);
}
int main(){
    cin >> n; m=(2*n*n)/9;
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); h[v].pb(u);
    }
    if (n==1) return 0;
    if (n==2){puts("1 2 1");return 0;}
    for (int i=1;i<=n;i++) {
        dfs(i,0); p=0; q=0;
        int pos=-1;
        for (auto v:h[i]) if (sz[v]>=n/3&&n-sz[v]>=n/3){
            pos=v;
            break;
        }
        memset(color,0,sizeof(color));
        if (pos==-1){
            for (auto v:h[i]){
                if (p<=q) color[v]=1,p+=sz[v];
                else color[v]=2,q+=sz[v];
            }
        } else {
            for (auto v:h[i]){
                if (pos==v) color[v]=1,p+=sz[v];
                else color[v]=2,q+=sz[v];
            }
        }
        if ((p+1)*(q+1)-1>=m){
            pp=0; qq=0;
            for (auto v:h[i]) dfs2(v,i,color[v]);
            return 0;
        }
    }
    assert(0);
}