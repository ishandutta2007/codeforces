#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=500005;
typedef std::pair<int,int> pi;
std::vector<int> e[N];int anc[N][20],dep[N],Fa[N],dfn[N],o[N],tid,siz[N];
int fa[N<<1];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){x=find(x),y=find(y);if(x!=y)fa[x]=y;}
void dfs1(int x,int fa){
	anc[x][0]=Fa[x]=fa,dep[x]=dep[fa]+1,o[++tid]=x,dfn[x]=tid,siz[x]=1;
	for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto v:e[x])if(v!=fa)dfs1(v,x),siz[x]+=siz[v];
}
int a[N],b[N],n,c[N],d[N],f[N],L[N+N],R[N+N],all[N];
bool vis[N],rev[N],__[N];
bool check(int k,bool tag=0){
	memset(vis,0,sizeof(vis));
	for(int _=n;_>=1;--_){
		int x=o[_],pos=0;
		for(auto v:e[x])if(v!=Fa[x]&&a[v]){
			int B=c[v],b=B>n?B-n:B;
			if(!vis[b])vis[b]=1,L[b]=1,R[b]=k,all[pos++]=b;
			B<=n?chmax(L[b],f[v]+1):chmin(R[b],k-f[v]);
		}
		int tar=c[x]>n?c[x]-n:c[x],ll=1,rr=k,mid=(k+1)/2,l=1,r=mid;
		for(int _=0;_<pos;++_){
			int i=all[_];
			if(i==tar){ll=L[i],rr=R[i];continue;}
			int x=L[i],y=R[i];if(x>y)return false;
			if(k+1-x<x)std::swap(x,y),x=k+1-x,y=k+1-y;
			if(k+1-y<=y)chmax(l,std::min(x,k+1-y));
			else{
				if(x>mid)std::swap(x,y),x=k+1-x,y=k+1-y;
				chmax(l,x),chmin(r,y);
			}
		}
		if(c[x]>n)std::swap(ll,rr),ll=k+1-ll,rr=k+1-rr;
		if(ll>rr||l>r)return false;
		std::array<int,6> v={ll,rr,l,r,k+1-r,k+1-l};
		std::sort(v.begin(),v.end());
		f[x]=0;for(auto it:v)if(ll<=it&&it<=rr&&((l<=it&&it<=r)||(k+1-r<=it&&it<=k+1-l))){f[x]=it;break;}
		if(!f[x])return false;
		if(tag){
			for(int _=0,i;_<pos;++_)i=all[_],__[i]=!(L[i]<=f[x]&&f[x]<=R[i]);
			for(auto v:e[x])if(v!=Fa[x]&&a[v]){
				int B=c[v],b=B<=n?B:B-n;
				if((B>n)^(b==tar?(c[x]>n):__[b]))rev[v]^=1;
			}
		}
		for(int i=0;i<pos;++i)vis[all[i]]=0;
	}
	return true;
}
int main(){
	int m;read(n,m);
	std::iota(fa+1,fa+n+n+1,1);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0);
	for(int i=1,x,y;i<=m;++i){
		read(x,y);if(dfn[x]>dfn[y])std::swap(x,y);
		if(dfn[y]<dfn[x]+siz[x]){
			int u=y,k=dep[y]-dep[x]-1;for(int i=19;i>=0;--i)if(k>>i&1)u=anc[u][i];
			++a[y],--a[x],++b[y],--b[u];
		}
		else{
			int u=x,v=y;
			if(dep[u]<dep[v])std::swap(u,v);
			for(int i=19;i>=0;--i)if(dep[anc[u][i]]>=dep[v])u=anc[u][i];
			for(int i=19;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
			++a[x],++a[y],a[Fa[u]]-=2;	
			++b[x],++b[y],--b[u],--b[v];
			merge(x,y+n),merge(x+n,y);
		}
	}
	for(int i=n;i>1;--i)a[Fa[o[i]]]+=a[o[i]],b[Fa[o[i]]]+=b[o[i]];
	for(int i=1;i<=n;++i)if(b[i])merge(i,Fa[i]),merge(i+n,Fa[i]+n);
	for(int i=2;i<=n;++i){
		c[i]=find(i),d[i]=find(i+n);
		if(c[i]==d[i])return puts("-1"),0;
	}
	int l=1,r=n,mid;while(l<r)mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
	printf("%d\n",l),check(l,1);
	for(int i=1;i<=n;++i)rev[o[i]]^=rev[Fa[o[i]]];
	for(int i=1;i<=n;++i)printf("%d%c",rev[i]?l+1-f[i]:f[i]," \n"[i==n]);
	return 0;
}