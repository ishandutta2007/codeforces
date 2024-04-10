#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring> 
using namespace std;
struct Edge{
	int to,next;
}e[500005];
int cnt,h[500005],n,m,K,d[500005],val[500005],dis[500005],f[5000005];
int size[500005],son[500005],id[500005],sign,ans[500005],L[500005],R[500005];
void Add_Edge(int x,int y) {
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
void DFS(int now,int depth,int dist){
	d[now]=depth,size[now]=1,L[now]=++sign;
	dist^=val[now];
	dis[now]=dist,id[sign]=now;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		DFS(y,depth+1,dist);
		size[now]+=size[y];
		if(size[son[now]]<size[y])son[now]=y;
	}
	R[now]=sign;
}
void Calc(int now,bool remain){
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==son[now])continue;
		Calc(y,0),ans[now]=max(ans[now],ans[y]);
	}
	if(son[now])Calc(son[now],1),ans[now]=max(ans[now],ans[son[now]]);
	ans[now]=max(ans[now],f[dis[now]]-d[now]);
	for(int i=0;i<22;i++)ans[now]=max(ans[now],f[dis[now]^(1<<i)]-d[now]);
	f[dis[now]]=max(f[dis[now]],d[now]);
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==son[now])continue;
		for(int j=L[y];j<=R[y];j++){
			int u=id[j];
			if(f[dis[u]])ans[now]=max(ans[now],f[dis[u]]+d[u]-2*d[now]);
			for(int k=0;k<22;k++)if(f[dis[u]^(1<<k)])ans[now]=max(ans[now],f[dis[u]^(1<<k)]+d[u]-2*d[now]);
		}
		for(int j=L[y];j<=R[y];j++)f[dis[id[j]]]=max(f[dis[id[j]]],d[id[j]]);
	}
	if(!remain)for(int i=L[now];i<=R[now];i++)f[dis[id[i]]]=0;
}
int main() {
	scanf("%d",&n);
	char str[2];
	for(int i=2,x;i<=n;i++)scanf("%d%s",&x,str),val[i]=1<<(str[0]-'a'),Add_Edge(x,i);
	DFS(1,0,1);
	Calc(1,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}