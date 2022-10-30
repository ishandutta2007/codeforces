#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300015;
std::vector<int> E[N],e[N],r[N];bool a[N],f[N],g[N],F[N],G[N];
inline void addedge(int x,int y){if(y==x+1)a[x]=1;else E[x].pb(y);}
inline void ADDEDGE(int x,int y){e[x].pb(y),r[y].pb(x);}
void dfs1(int x){f[x]=1;for(auto v:r[x])if(!f[v])dfs1(v);}
void dfs2(int x){g[x]=1;for(auto v:e[x])if(!g[v])dfs2(v);}
void dfs3(int x){F[x]=1;for(auto v:r[x])if(!F[v])dfs3(v);}
void dfs4(int x){G[x]=1;for(auto v:e[x])if(!G[v])dfs4(v);}
void MAIN(){
	int n,m;read(n,m),++n;
	memset(a,0,sizeof(a));
	for(int i=0;i<=n;++i)E[i].clear();
	for(int i=0;i<=n+n;++i)e[i].clear(),r[i].clear();
	for(int i=1,x,y;i<=m;++i)read(x,y),addedge(x,y);
	for(int i=1;i<=n;++i)addedge(0,i);
	for(int i=1;i<n;++i)addedge(i,n);
	int x=0;while(x<n&&a[x])++x;
	int y=n;while(y>=1&&a[y-1])--y;
	if(x==n)return printf("%lld\n",1LL*(n-1)*(n-2)/2),void();
	for(int i=n,last=n;i>=1;--i){
		if(!a[i])last=i;
		for(auto v:E[i-1])if(v-1<=last)ADDEDGE(i,v+n),ADDEDGE(i+n,v);
	}
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),memset(F,0,sizeof(F)),memset(G,0,sizeof(G));
	long long ans=0;int c0=0,c1=0;dfs1(x+1),dfs2(x+1);
	for(int i=1;i<=x+1;++i)c0+=f[i+n];
	for(int i=y;i<=n;++i)c1+=g[i+n];
	ans+=1LL*c0*c1,dfs3(x+1+n),dfs4(x+1+n),c0=0,c1=0;
	for(int i=1;i<=x+1;++i)c0+=F[i+n];
	for(int i=y;i<=n;++i)c1+=G[i+n];
	ans+=1LL*c0*c1,c0=0,c1=0;
	for(int i=1;i<=x+1;++i)c0+=f[i+n]&&F[i+n];
	for(int i=y;i<=n;++i)c1+=g[i+n]&&G[i+n];
	ans-=1LL*c0*c1;
	printf("%lld\n",ans-(x+1==y));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}