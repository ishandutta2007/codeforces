#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+6;
typedef long long ll;
vector <int> h[maxn];
int n,p,q,flag;
void dfs(int u,int fa,int o){
    if (h[u].size()==1) flag|=o;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u,o^1);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    q=n-1;
    for (int i=1;i<=n;i++){
        int cnt=0;
        for (auto j:h[i]) if (h[j].size()==1) cnt++;
        if (cnt>1) q-=cnt-1;
    }
    for (int i=1;i<=n;i++) if (h[i].size()==1){
        dfs(i,0,0); break;
    }
    if (flag) p=3; else p=1;
    printf("%d %d\n",p,q);
    return 0;
}