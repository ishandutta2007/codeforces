#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,ll>pi;
typedef vector<int>vi;
const int maxn=5e5+20;
const int M=998244353;
vector<pi> G[maxn];
bool vis[maxn];
int n,m,st[maxn],dfn[maxn],low[maxn],top,cnt,color,col[maxn],q;
ll dep[maxn],ans[maxn],res[maxn];
void tarjan(int u){
	vis[u]=1;
	st[++top]=u;
	dfn[u]=low[u]=++cnt;
	for (auto e:G[u]){
		int v=e.F;
		if (!dfn[v]){
			dep[v]=dep[u]+e.S; tarjan(v);
			low[u]=min(low[u],low[v]);
		} else if (vis[v]){
			low[u]=min(low[u],low[v]);
			if (dep[u]<dep[v]) res[u]=__gcd(res[u],abs(dep[v]-dep[u]-e.S));
			else res[u]=__gcd(res[u],dep[u]-dep[v]+e.S);
		}
	}
	if (dfn[u]==low[u]){
        color++;
        while (st[top+1]!=u){
			col[st[top]]=color;
			ans[color]=__gcd(ans[color],res[st[top]]);
			vis[st[top--]]=0;
        }
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;ll w; scanf("%d%d%lld",&u,&v,&w);
		G[u].pb((pi){v,w});
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	//for (int i=1;i<=n;i++)cout<<col[i]<<' ';cout<<endl;
	//for (int i=1;i<=color;i++)cout<<ans[i]<<' ';cout<<endl;

	scanf("%d",&q);
	while (q--){
		int u;ll s,t;scanf("%d%lld%lld",&u,&s,&t);
		ll r=ans[col[u]];
        if (s%__gcd(t,r)) puts("NO"); else puts("YES");
	}

	return 0;
}