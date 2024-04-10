#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct Query{
	int opt,x,rx,ry;
}q[500005];
int n,m,Q,fa[200005],ex[300005],ey[300005],del[300005],sz[300005],bel[200005],a[200005],used[200005];
vector<int> h[200005];
int gf(int x){
	return fa[x]==x?x:gf(fa[x]);
}
int Query(int x){
	while(h[x].size()&&(bel[h[x].back()]!=x||used[h[x].back()]))h[x].pop_back();
	if(!h[x].size())return 0;
	int r=h[x].back();
	return h[x].pop_back(),used[r]=1,r;
}
int main() {
	n=read(),m=read(),Q=read();
	for(int i=1,x;i<=n;++i)h[fa[i]=i].push_back(a[i]=x=read()),sz[i]=1;
	for(int i=1;i<=m;++i)ex[i]=read(),ey[i]=read();
	for(int i=1;i<=Q;++i){
		q[i].opt=read(),q[i].x=read();
		if(q[i].opt==2)del[q[i].x]=1;
	}
	for(int i=1;i<=m;++i){
		if(del[i])continue;
		int x=gf(ex[i]),y=gf(ey[i]);
		if(x==y)continue;
		if(sz[x]>sz[y])swap(x,y);
		for(int j:h[x])h[y].push_back(j);
		fa[x]=y,sz[y]+=sz[x];
	}
	for(int i=Q;i>=1;i--){
		int x=ex[q[i].x],y=ey[q[i].x];
		if(q[i].opt==1||gf(x)==gf(y))continue;
		x=gf(x),y=gf(y);
		if(sz[x]>sz[y])swap(x,y);
		q[i].rx=x,q[i].ry=y,fa[x]=y,sz[y]+=sz[x];
		for(int j:h[x])h[y].push_back(j);
	}
	for(int i=1;i<=n;++i)sort(h[i].begin(),h[i].end()),bel[a[i]]=gf(i);
	for(int i=1,u;i<=Q;++i){
		if(q[i].opt==1)printf("%d\n",u=Query(gf(q[i].x)));
		else if(q[i].rx){
			for(int j:h[q[i].rx])bel[j]=q[i].rx;
			fa[q[i].rx]=q[i].rx;
		}
	}
	return 0;
}