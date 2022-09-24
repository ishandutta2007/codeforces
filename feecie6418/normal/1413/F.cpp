#include<bits/stdc++.h>
using namespace std;
struct E {
	int to,val;
};
struct Edge {
	int x,y;
} e[500005];
vector<E> g[500005];
int n,m;
namespace Solve1 {
	struct P {
		int mx[2];
		int& operator [](int k) {
			return mx[k];
		}
	} t[2000005];
	P operator +(P a,P b) {
		return {max(a[0],b[0]),max(a[1],b[1])};
	}
	int tag[2000005],dfn[500005],sign,size[500005];
	void Upd(int p,int l,int r,int x,int z,int w) {
		if(l==r)return t[p][z]=w,t[p][z^1]=0,void();
		int mid=(l+r)/2;
		if(x<=mid)Upd(p*2,l,mid,x,z,w);
		else Upd(p*2+1,mid+1,r,x,z,w);
		t[p]=t[p*2]+t[p*2+1];
	}
	void Tag(int p) {
		tag[p]^=1,swap(t[p][0],t[p][1]);
	}
	void Pushdown(int p) {
		if(tag[p])Tag(p*2),Tag(p*2+1),tag[p]=0;
	}
	void Rev(int p,int l,int r,int x,int y) {
		if(x<=l&&r<=y)return Tag(p),void();
		Pushdown(p);
		int mid=(l+r)/2;
		if(x<=mid)Rev(p*2,l,mid,x,y);
		if(mid<y)Rev(p*2+1,mid+1,r,x,y);
		t[p]=t[p*2]+t[p*2+1];
	}
	void dfs2(int x,int f,int di,int v) {
		size[x]=1,dfn[x]=++sign,Upd(1,1,n,dfn[x],v,di);
		for(E i:g[x]) {
			int y=i.to;
			if(y==f)continue;
			dfs2(y,x,di+1,v^i.val),size[x]+=size[y];
		}
	}
	void Init(int L){
		dfs2(L,0,0,0);
	}
	int s(int x){
		if(dfn[e[x].x]<dfn[e[x].y])swap(e[x].x,e[x].y);
		Rev(1,1,n,dfn[e[x].x],dfn[e[x].x]+size[e[x].x]-1);
		return t[1][0];
	}
}
namespace Solve2 {
	struct P {
		int mx[2];
		int& operator [](int k) {
			return mx[k];
		}
	} t[2000005];
	P operator +(P a,P b) {
		return {max(a[0],b[0]),max(a[1],b[1])};
	}
	int tag[2000005],dfn[500005],sign,size[500005];
	void Upd(int p,int l,int r,int x,int z,int w) {
		if(l==r)return t[p][z]=w,t[p][z^1]=0,void();
		int mid=(l+r)/2;
		if(x<=mid)Upd(p*2,l,mid,x,z,w);
		else Upd(p*2+1,mid+1,r,x,z,w);
		t[p]=t[p*2]+t[p*2+1];
	}
	void Tag(int p) {
		tag[p]^=1,swap(t[p][0],t[p][1]);
	}
	void Pushdown(int p) {
		if(tag[p])Tag(p*2),Tag(p*2+1),tag[p]=0;
	}
	void Rev(int p,int l,int r,int x,int y) {
		if(x<=l&&r<=y)return Tag(p),void();
		Pushdown(p);
		int mid=(l+r)/2;
		if(x<=mid)Rev(p*2,l,mid,x,y);
		if(mid<y)Rev(p*2+1,mid+1,r,x,y);
		t[p]=t[p*2]+t[p*2+1];
	}
	void dfs2(int x,int f,int di,int v) {
		size[x]=1,dfn[x]=++sign,Upd(1,1,n,dfn[x],v,di);
		for(E i:g[x]) {
			int y=i.to;
			if(y==f)continue;
			dfs2(y,x,di+1,v^i.val),size[x]+=size[y];
		}
	}
	void Init(int L){
		dfs2(L,0,0,0);
	}
	int s(int x){
		if(dfn[e[x].x]<dfn[e[x].y])swap(e[x].x,e[x].y);
		Rev(1,1,n,dfn[e[x].x],dfn[e[x].x]+size[e[x].x]-1);
		return t[1][0];
	}
}
void dfs1(int x,int f,int di,int &var,int &mx) {
	if(di>mx)mx=di,var=x;
	for(E i:g[x]) {
		int y=i.to;
		if(y==f)continue;
		dfs1(y,x,di+1,var,mx);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1,x,y,z; i<n; i++)scanf("%d%d%d",&x,&y,&z),g[x].push_back({y,z}),g[y].push_back({x,z}),e[i]= {x,y};
	int L=0,R=0,mx=-1;
	dfs1(1,0,0,L,mx),mx=-1,dfs1(L,0,0,R,mx),scanf("%d",&m);
	Solve1::Init(L),Solve2::Init(R);
	while(m--) {
		int x;
		scanf("%d",&x),printf("%d\n",max(Solve1::s(x),Solve2::s(x)));
	}
}