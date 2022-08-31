#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+3;
vector <int> h[maxn];
long long ans;
int n,m,d[maxn];
long long ask(int x){return 1ll*h[x].size()*(d[x]-h[x].size());}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        d[u]++; d[v]++;
        if (u>v) swap(u,v);
        h[u].pb(v);
    }
    for (int i=1;i<=n;i++) ans+=ask(i);
    printf("%lld\n",ans);
    int _; scanf("%d",&_);
    while (_--){
        int u; scanf("%d",&u);
        ans-=ask(u);
        for (auto v:h[u]){
            ans-=ask(v);
            h[v].pb(u);
            ans+=ask(v);
        }
        h[u].clear();
        printf("%lld\n",ans);
    }
}