#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
int c[maxn],n,m,_,vis[maxn],id[maxn],cc,p[maxn];
vector<int>G[maxn];
void dfs(int u){
    id[u]=++cc; vis[u]=1;
    for (auto v:G[u]) if (!vis[v]) dfs(v);
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		vis[i]=0;
		G[i].clear();
	}
	while (m--){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v); G[v].pb(u);
	}
    cc=0; dfs(1);
    if (cc<n) {puts("NO");return;}
    for (int i=1;i<=n;i++) p[id[i]]=i;
    for (int i=1;i<=n;i++){
		int u=p[i]; c[u]=1;
		for (auto v:G[u]) if (id[v]<id[u]) c[u]&=!c[v];
    }
    vector<int> ans; ans.clear();
    for (int i=1;i<=n;i++) if (c[i]) ans.pb(i);
    puts("YES");printf("%d\n",(int)ans.size());
    for (auto x:ans) printf("%d ",x);puts("");
}
int main(){
	scanf("%d",&_);
	while (_--) solve();
	return 0;
}