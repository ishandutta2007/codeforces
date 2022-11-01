#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

int n,a[100005],ans[100005];
struct edge{int u,v,w,pre;}e[200005]; int dex,adj[100005];
struct Ques{int x,y,v,id;}Q[100005]; int tQ;
int fa[100005],dep[100005],hev[100005],sz[100005],top[100005];
int dfn[100005],Ind[100005],ttt;
struct Info{
	int lx,rx,sm,len;
	inline Info operator +(const Info &A)const{
		if(!len) return A;
		if(!A.len) return *this;
		Info res=*this; res.len+=A.len;
		if(lx==len && rx==len && A.lx==A.len && A.rx==A.len){
			res.lx=res.rx=res.len;
			res.sm=0;
			return res;
		}
		if(A.lx==A.len && A.rx==A.len){
			res.rx=A.len+rx;
			res.lx=lx;
			res.sm=sm;
			return res;
		}
		if(lx==len && rx==len){
			res.lx=len+A.lx;
			res.rx=A.rx;
			res.sm=A.sm;
			return res;
		}
		res.lx=lx; res.rx=A.rx;
		res.sm=sm+A.sm+a[rx+A.lx];
		return res;
	}
}t[400005],resL,resR;
int all[400005];

inline int operator <(const Ques &A,const Ques &B){
	return A.v>B.v;
}

inline int operator <(const edge &A,const edge &B){
	return A.w>B.w;
}

void dfs(int x){
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		if(v==fa[x])continue;
		fa[v]=x; dep[v]=dep[x]+1;
		dfs(v);
		sz[x]+=sz[v];
		if(sz[v]>sz[hev[x]]) hev[x]=v;
	} ++sz[x];
}

void build(int x){
	dfn[x]=++ttt;
	Ind[ttt]=x;
	if(hev[x]){
		top[hev[x]]=top[x];
		build(hev[x]);
	}
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		if(v==fa[x])continue;
		if(v==hev[x])continue;
		top[v]=v;
		build(v);
	}
}

void Mod(int x,int L,int R,int v){
	if(L==R){
		t[x].lx=t[x].rx=t[x].len=1;
		t[x].sm=0;
		return;
	}
	int md=(L+R)>>1;
	if(v<=md) Mod(x*2,L,md,v);
	else Mod(x*2+1,md+1,R,v);
	if(all[x]) t[x]=t[x*2]+t[x*2+1];
}

void build_tree(int x,int L,int R){
	if(L==R){
		t[x].len=1;
		t[x].lx=t[x].rx=0;
		t[x].sm=0;
		all[x]=top[Ind[L]];
		return;
	}
	int md=(L+R)>>1;
	build_tree(x*2,L,md);
	build_tree(x*2+1,md+1,R);
	if(all[x*2]==all[x*2+1] && all[x*2]>0) all[x]=all[x*2];
	else all[x]=0;
	if(all[x]) t[x]=t[x*2]+t[x*2+1];
}

Info ask(int x,int L,int R,int ll,int rr){
	if(ll<=L && R<=rr) return t[x];
	if(ll>rr) return (Info){0,0,0,0};
	int md=(L+R)>>1;
	Info res=(Info){0,0,0,0};
	if(ll<=md) res=res+ask(x*2,L,md,ll,rr);
	if(md<rr)  res=res+ask(x*2+1,md+1,R,ll,rr);
	return res;
}

int ask(int x,int y){
	resL.len=resL.lx=resL.rx=resL.sm=0;
	resR.len=resR.lx=resR.rx=resR.sm=0;
	for(;top[x]^top[y];){
		if(dep[top[x]]<dep[top[y]]){
			resR=ask(1,1,n,dfn[top[y]],dfn[y])+resR;
			y=fa[top[y]];
		}else{
			Info tmp=ask(1,1,n,dfn[top[x]],dfn[x]);
			swap(tmp.lx,tmp.rx);
			resL=resL+tmp;
			x=fa[top[x]];
		}
	}
	if(dep[x]<=dep[y]){
		resL=resL+ask(1,1,n,dfn[x]+1,dfn[y])+resR;
		if(resL.lx==resL.len && resL.rx==resL.len) return a[resL.lx];
		return a[resL.lx]+a[resL.rx]+resL.sm;
	}else{
		Info tmp=ask(1,1,n,dfn[y]+1,dfn[x]);
		swap(tmp.lx,tmp.rx);
		resR=resL+tmp+resR;
		if(resR.lx==resR.len && resR.rx==resR.len) return a[resR.lx];
		return a[resR.lx]+a[resR.rx]+resR.sm;
	}
}

int main(){
	scanf("%d%d",&n,&tQ);
	For(i,1,n-1) scanf("%d",a+i);
	For(i,1,n-1){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[++dex]=(edge){x,y,w,adj[x]}; adj[x]=dex;
		e[++dex]=(edge){y,x,w,adj[y]}; adj[y]=dex;
	}
	For(i,1,tQ){
		scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].v);
		Q[i].id=i;
	}
	dep[1]=top[1]=1;
	dfs(1);
	build(1);
	build_tree(1,1,n);
	sort(Q+1,Q+tQ+1);
	sort(e+1,e+dex+1);
	int now=1;
	For(i,1,tQ){
		while(now<=dex && e[now].w>=Q[i].v){
			if(dep[e[now].u]<dep[e[now].v]) Mod(1,1,n,dfn[e[now].v]);
			++now;
		}
		ans[Q[i].id]=ask(Q[i].x,Q[i].y);
	}
	For(i,1,tQ) printf("%d\n",ans[i]);
	return 0;
}