
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char buf[2000005];
int pt=2000000;
char gc(){
	if(pt>=2000000)fread(buf,1,2000000,stdin),pt=0;
	return buf[pt++];
}
int rd(){
	int x=0,ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))x=x*10+ch-'0',ch=gc();
	return x;
}
struct Query{
	int opt,x,rx,ry;
}q[500005];
int n,m,Q,fa[200005],ex[300005],ey[300005],del[300005],sz[300005],bel[200005],a[200005],used[200005];
vector<int> h[200005];
vector<int> vec[200005];
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
	n=rd(),m=rd(),Q=rd();
	for(int i=1,x;i<=n;i++)x=rd(),h[fa[i]=i].push_back(a[i]=x),sz[i]=1;
	for(int i=1;i<=m;i++)ex[i]=rd(),ey[i]=rd();
	for(int i=1;i<=Q;i++){
		q[i].opt=rd(),q[i].x=rd();
		if(q[i].opt==2)del[q[i].x]=1;
	}
	for(int i=1;i<=m;i++){
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
	for(int i=1;i<=n;i++){
		for(int j:h[i])vec[j].push_back(i);
		h[i].clear();
	}
	for(int i=1;i<=n;i++)for(int j:vec[i])h[j].push_back(i);
	for(int i=1;i<=n;i++)bel[a[i]]=gf(i);
	for(int i=1,u;i<=Q;i++){
		if(q[i].opt==1)printf("%d\n",u=Query(gf(q[i].x)));
		else if(q[i].rx){
			for(int j:h[q[i].rx])bel[j]=q[i].rx;
			fa[q[i].rx]=q[i].rx;
		}
	}
	return 0;
}