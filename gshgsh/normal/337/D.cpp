#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 100001
int N,M,D,a[MAXN],fa[MAXN][20],dep[MAXN],f[MAXN],s[MAXN],mxsiz,sum,r,cnt[MAXN],lim[MAXN],tot[2][MAXN],*c[2][MAXN];bool vis[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){dep[u]=dep[f]+1;fa[u][0]=f;For(i,1,19)fa[u][i]=fa[fa[u][i-1]][i-1];for(auto v:E[u])if(v!=f)dfs(v,u);}
int lca(int x,int y){if(dep[x]<dep[y])swap(x,y);FOR(i,19,0)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];FOR(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return x==y?x:fa[x][0];}
int dis(int x,int y){return 0ll+dep[x]+dep[y]-dep[lca(x,y)]*2;}
void getrt(int u,int f){s[u]=1;int mx=0;for(auto v:E[u])if(v!=f&&!vis[v])getrt(v,u),s[u]+=s[v],mx=max(mx,s[v]);if(max(mx,sum-s[u])<mxsiz)r=u,mxsiz=max(mx,sum-s[u]);}
void getsiz(int u,int f){s[u]=1;for(auto v:E[u])if(v!=f&&!vis[v])getsiz(v,u),s[u]+=s[v];}
void build(int u)
{
	vis[u]=1;cnt[u]=1;for(auto v:E[u])if(!vis[v])getsiz(v,0),cnt[u]+=s[v];lim[u]=cnt[u]+1;c[0][u]=new int[lim[u]+1]();c[1][u]=new int[lim[u]+1]();
	for(auto v:E[u])if(!vis[v])mxsiz=sum=s[v],getrt(v,0),f[r]=u,build(r);
}
int ask(int*x,int lim,int v){return upper_bound(x+1,x+lim+1,v)-x-1;}
int main()
{
	N=get(),M=get(),D=get();For(i,1,M)a[get()]=1;For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);mxsiz=sum=N;getrt(1,0);build(r);For(i,1,N)cnt[i]=0;For(i,1,N)if(a[i]){cnt[i]++;for(int j=f[i],pre=i;j;j=f[pre=j])cnt[j]++;}
	For(i,1,N)c[0][i]=new int[cnt[i]+1](),c[1][i]=new int[cnt[i]+1]();
	For(i,1,N)if(a[i]){c[0][i][++tot[0][i]]=0;for(int j=f[i],pre=i;j;j=f[pre=j])c[0][j][++tot[0][j]]=c[1][pre][++tot[1][pre]]=dis(i,j);}
	For(i,1,N)For(j,0,1)sort(c[j][i]+1,c[j][i]+tot[j][i]+1);
	int ans=0;For(i,1,N){int sum=ask(c[0][i],tot[0][i],D),pre=i;if(sum!=cnt[i])continue;for(int j=f[i];j;j=f[pre=j]){int l=dis(i,j);if(D>=l)sum+=ask(c[0][j],tot[0][j],D-l)-ask(c[1][pre],tot[1][pre],D-l);if(sum!=cnt[j])break;}ans+=sum==M;}cout<<ans<<'\n';return 0;
}