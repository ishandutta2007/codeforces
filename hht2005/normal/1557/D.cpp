#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10,mod=998244353;
int c[N],Min[N<<2],tag[N<<2],f[N],pre[N],T[N];
vector<pair<int,int> >pos[N];
#define lb(x) (lower_bound(c+1,c+M+1,x)-c)
void make_tag(int p,int v) {
	if(f[tag[p]]-tag[p]>f[v]-v)tag[p]=v;
	if(f[Min[p]]-Min[p]>f[v]-v)Min[p]=v;
}
void push_down(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
int get_min(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Min[p];
	push_down(p);
	int mid=(l+r)>>1,lM=0,rM=0;
	if(x<=mid)lM=get_min(p<<1,l,mid,x,y);
	if(y>mid)rM=get_min(p<<1|1,mid+1,r,x,y);
	if(f[lM]-lM<f[rM]-rM)return lM;
	return rM;
}
void mdf_min(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)mdf_min(p<<1,l,mid,x,y,v);
	if(y>mid)mdf_min(p<<1|1,mid+1,r,x,y,v);
	int lM=Min[p<<1],rM=Min[p<<1|1];
	if(f[lM]-lM<f[rM]-rM)Min[p]=lM;
	else Min[p]=rM;
}
int main() {
	int n,m,x,l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&l,&r);
		c[2*i-1]=l,c[2*i]=r;
		pos[x].push_back(make_pair(l,r));
	}
	sort(c+1,c+2*m+1);
	int M=unique(c+1,c+2*m+1)-c-1,ans=1e9,las=0;
	for(int i=1;i<=n;i++) {
		int v=0;
		for(pair<int,int> t:pos[i]) {
			int u=get_min(1,1,M,lb(t.first),lb(t.second));
			if(f[v]-v>f[u]-u)v=u;
		}
		f[i]=f[v]+i-v-1;
		pre[i]=v;
		for(pair<int,int> t:pos[i])
			mdf_min(1,1,M,lb(t.first),lb(t.second),i);
		if(f[i]+n-i<ans)
			ans=f[las=i]+n-i;
	}
	printf("%d\n",ans);
	while(las) {
		T[las]=1;
		las=pre[las];
	}
	for(int i=1;i<=n;i++)
		if(!T[i])printf("%d ",i);
	puts("");
	return 0;
}