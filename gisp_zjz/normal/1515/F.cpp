#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=3e5+20;
const int M=998244353;
int pre[maxn],n,m,sz[maxn];
bool ban[maxn];
vi ans;
ll a[maxn],x,tot[maxn],sum;
vector<pi> G[maxn];
vi vcd;
int ffind(int x){
	if (pre[x]==x) return x;
	return pre[x]=ffind(pre[x]);
}
void dfs(int u,int fa){
	sz[u]=1; tot[u]=a[u]; pre[u]=fa;
	for (auto e:G[u]){
		int v=e.F;
		if (v==fa) continue;
		dfs(v,u);
		if (tot[v]>=sz[v]*x){
            tot[u]+=tot[v]-sz[v]*x;
            ans.pb(e.S); ban[e.S]=1; vcd.pb(v);
		} else {
			sz[u]+=sz[v];
			tot[u]+=tot[v];
		}
	}
}
void dfs1(int u,int fa){
	for (auto e:G[u]){
		int v=e.F;
		if (v==fa) continue;
		if (ban[e.S]) continue;
		ans.pb(e.S);
		dfs1(v,u);
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&x);
	for (int i=1;i<=n;i++) pre[i]=i;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) sum+=a[i];
	for (int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		if (ffind(u)==ffind(v)) continue;
		G[u].pb((pi){v,i}); G[v].pb((pi){u,i});
		pre[ffind(v)]=ffind(u);
	}
	if (sum<x*(n-1)){puts("NO");return 0;}
	dfs(1,0);
	vcd.pb(1);
	for (auto x:vcd) dfs1(x,pre[x]);
	puts("YES");
	for (auto x:ans) printf("%d\n",x);
	return 0;
}