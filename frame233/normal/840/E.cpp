#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=50005;
int a[N];std::vector<int> e[N];
int f[256][N],g[N][256],Fa[N],dep[N],I,v[N][17],p[N],FFa[N],t[N*2],tp;
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1,Fa[x]=fa;int u=x;t[++tp]=x;
	for(int i=0;i<256&&u;++i,u=Fa[u])chmax(g[x][a[u]>>8],a[u]^i);
	FFa[x]=u;for(auto v:e[x])if(v!=fa)dfs1(v,x);
	t[++tp]=-x;
}
int c[N];void add(int x,int C,int *v,int &p){for(;x;x-=lowbit(x))v[p++]=c[x],chmax(c[x],C);}
int ask(int x){int ans=0;for(;x<N;x+=lowbit(x))chmax(ans,c[x]);return ans;}
void recover(int x,int *v){int p=0;for(;x;x-=lowbit(x))c[x]=v[p++];}
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0);
	for(I=0;I<256;++I){
		for(int i=1;i<=tp;++i){
			int x=t[i];
			if(x>0){
				p[x]=0,add(dep[x],(a[x]>>8)^I,v[x],p[x]);
				int tmp=ask(std::max(dep[x]-255,1));f[I][x]=g[x][tmp^I]^(I<<8);
			}
			else x*=-1,recover(dep[x],v[x]);
		}
	}
	while(q--){
		int u,v;read(u,v);int ans=0,c=0;
		while(dep[v]-dep[u]>=256)chmax(ans,f[c++][v]),v=FFa[v];
		c*=256;while(dep[v]>=dep[u])chmax(ans,a[v]^(c++)),v=Fa[v];
		printf("%d\n",ans);
	}
	return 0;
}