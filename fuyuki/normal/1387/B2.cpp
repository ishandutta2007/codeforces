#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1,INF=0x3f3f3f3f;
ll ans;
priority_queue<P>q;
vector<int>e[N],t[N];
int n,x,y,z,rt,tot,minn=INF,siz[N],a[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs1(int u,int fa=0){
	int maxn(siz[u]=1);
	for(int v:e[u])if(v!=fa)
		dfs1(v,u),siz[u]+=siz[v],maxn=max(maxn,siz[v]);
	if((maxn=max(maxn,n-siz[u]))<minn)minn=maxn,rt=u;
}
V dfs2(int u,int fa=0,int d=1){
	t[tot].push_back(u),ans+=d*2;
	for(int v:e[u])if(v!=fa)dfs2(v,u,d+1);
}
I top(){
	int x=q.top().second;
	return q.pop(),x;
}
V push(int x){if(!t[x].empty())q.push(P(t[x].size(),x));}
V two(){
	int x=top(),y=top();
	a[t[x].back()]=t[y].back(),a[t[y].back()]=t[x].back();
	t[x].pop_back(),push(x),t[y].pop_back(),push(y);
}
V three(){
	int x=top(),y=top(),z=top();
	a[t[x].back()]=t[y].back(),a[t[y].back()]=t[z].back(),a[t[z].back()]=t[x].back();
	t[x].pop_back(),push(x),t[y].pop_back(),push(y),t[z].pop_back(),push(z);
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&n);
	FOR(i,2,n)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs1(1),t[++tot].push_back(rt);
	for(int v:e[rt])++tot,dfs2(v,rt),q.push(P(t[tot].size(),tot));
	cout<<ans<<'\n',q.push(P(1,1));
	if(n&1)three();
	while(!q.empty())two();
	FOR(i,1,n)cout<<a[i]<<' ';
	return 0;
}