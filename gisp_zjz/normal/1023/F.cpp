#include<bits/stdc++.h>
#define maxn 855555
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll inf=2e9;
typedef pair<int,ll> pi;
vector <pi> h[maxn];
int n,m,k,pre[maxn],H[maxn],t,pp[maxn],Fa[maxn],dep[maxn],sz[maxn];
ll ans[maxn],sum;
struct edge{
    int u,v;
    ll val;
}e[maxn],_e[maxn];
bool cmp(edge u,edge v){
    return u.val<v.val;
}
void union_(int u,int v){
    pre[v]=u;
}
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]); return pre[x];
}
void dfs(int u,int fa){
    sz[u]=1; pp[u]=fa;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i].F;
        if (v==fa) continue;
        ans[v]=h[u][i].S; dep[v]=dep[u]+1;
        dfs(v,u); sz[u]+=sz[v];
    }
}
void dfs2(int u,int fa){
    if (!fa) fa=u;
	Fa[u]=fa;
	int p,q; p=q=0;
	for (int i=0;i<h[u].size();i++) {
        int v=h[u][i].F;
		if (pp[u]==v) continue;
		if (sz[v]>p) p=sz[v],q=v;
	}
	if (q) dfs2(q,fa);
	for (int i=0;i<h[u].size();i++) {
        int v=h[u][i].F;
		if (pp[u]==v) continue;
		if (q==v) continue;
		dfs2(v,0);
	}
}
int get(int x,int y) {
	while (Fa[x]!=Fa[y]) {
		if (dep[Fa[x]]>dep[Fa[y]]) x=pp[Fa[x]];
		else y=pp[Fa[y]];
	}
	if (dep[x]>dep[y]) return y; else return x;
}
int main(){
    cin >> n >> k >> m;
    for (int i=1;i<=n;i++) pre[i]=i;
    for (int i=0;i<k;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].push_back((pi){v,inf});
        h[v].push_back((pi){u,inf});
        union_(ffind(u),ffind(v));
    }
    for (int i=0;i<m;i++) scanf("%d%d%I64d",&e[i].u,&e[i].v,&e[i].val);
    sort(e,e+m,cmp);
    for (int i=0;i<m;i++){
        int u=ffind(e[i].u),v=ffind(e[i].v);
        if (u==v) _e[t++]=e[i];
        else {
            union_(u,v);
            h[e[i].u].push_back((pi){e[i].v,0ll});
            h[e[i].v].push_back((pi){e[i].u,0ll});
        }
    }
    dfs(1,0);
    dfs2(1,0);
    for (int i=1;i<=n;i++) pre[i]=i;
	for (int i=0;i<t;i++) {
        int u,v,w;
        u=_e[i].u; v=_e[i].v; w=get(u,v);
		u=ffind(u);
		while (dep[u]>dep[w]) {
			ans[u]=min(ans[u],_e[i].val);
			pre[u]=ffind(pp[u]);
			u=ffind(u);
		}
		v=ffind(v);
		while (dep[v]>dep[w]) {
			ans[v]=min(ans[v],_e[i].val);
			pre[v]=ffind(pp[v]);
			v=ffind(v);
		}
	}
	sum=0;
	for (int i=2;i<=n;i++) {
		if (ans[i]==inf) {
            printf("-1\n");
            return 0;
		}
		sum+=ans[i];
	}
	printf("%I64d\n",sum);
}