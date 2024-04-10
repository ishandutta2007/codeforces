#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{
	int to,val;
};
vector<E> g[200005];
int n,loop[200005],sign,low[200005],dfn[200005],st[200005],top,onloop[200005],L,R;
ll dis[200005],fl[200005],pre[200005],ans=1e15,mx=0,lst[200005],pans[200005],sans[200005],oo=0,mxd=0,l[200005],r[200005];
void Tarjan(int x,int fa){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(E i:g[x]){
		int y=i.to;
		if(y==fa)continue;
		if(dfn[y])low[x]=min(low[x],dfn[y]);
		else Tarjan(y,x),low[x]=min(low[x],low[y]);
	}
	if(low[x]==dfn[x]){
		int tmp;
		if(st[top]==x)top--;
		else do {
			tmp=st[top--],loop[++loop[0]]=tmp,onloop[tmp]=1;
		} while(tmp!=x);
	}
}
void dfs(int x,int fa,int &p,ll dis,int f){
	if(dis>=mxd)mxd=dis,p=x;
	for(E i:g[x])if(i.to!=fa&&(!onloop[i.to]||i.to==f))dfs(i.to,x,p,dis+i.val,f);
}
int main() {
	cin>>n;
	int O=0;
	for(int i=1,x,y,z;i<=n;i++)cin>>x>>y>>z,g[x].push_back({y,z}),g[y].push_back({x,z}),O=(!O?x:O);
	Tarjan(1,0);
	for(int i=1;i<=loop[0];i++){
		mxd=0,dfs(loop[i],0,L,0,loop[i]),dis[i]=mxd;
		dfs(L,0,R,0,loop[i]),oo=max(oo,mxd);
	}
	for(E j:g[loop[1]])if(j.to==loop[loop[0]])lst[1]=j.val;
	for(int i=2;i<=loop[0];i++)for(E j:g[loop[i]])if(j.to==loop[i-1])lst[i]=j.val;
	for(int i=1;i<=loop[0];i++)lst[i]+=lst[i-1];
	mx=pans[0]=-1e15;
	for(int i=1;i<=loop[0];i++){
		pans[i]=max(pans[i-1],dis[i]+lst[i]+mx);
		mx=max(mx,dis[i]-lst[i]),l[i]=max(l[i-1],dis[i]+lst[i]);
	}
	mx=sans[loop[0]+1]=-1e15;
	for(int i=loop[0];i>=1;i--){
		sans[i]=max(sans[i+1],mx+dis[i]-lst[i]);
		mx=max(mx,dis[i]+lst[i]),r[i]=max(r[i+1],lst[loop[0]]+dis[i]-lst[i]);
	}
	for(int i=loop[0];i>=1;i--)ans=min(ans,max(l[i-1]+r[i],max(pans[i-1],sans[i])));
	printf("%lld\n",max(ans,oo));
}