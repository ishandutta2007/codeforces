#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,sum[MAXN],siz[MAXN],ans[MAXN];vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f)
{
	vector<pair<int,int>>son;for(auto v:E[u])if(v.first!=f)son.push_back(v);E[u]=son;siz[u]=1;
	for(auto v:E[u])sum[v.first]+=v.second,dfs(v.first,u),sum[u]+=sum[v.first],siz[u]+=siz[v.first];
}
void dfs1(int u){sort(E[u].begin(),E[u].end(),[](pair<int,int>a,pair<int,int>b){return 1ll*sum[a.first]*siz[b.first]<1ll*sum[b.first]*siz[a.first];});for(auto v:E[u])dfs1(v.first);}
void dfs2(int u,int t){ans[u]=t;for(auto v:E[u])dfs2(v.first,t+v.second),t+=sum[v.first]*2;}
int main()
{
	N=get();For(i,1,N-1){int u=get(),v=get(),w=get();E[u].push_back({v,w}),E[v].push_back({u,w});}
	dfs(1,0);dfs1(1);dfs2(1,0);double res=0;For(i,2,N)res+=ans[i];printf("%.12lf\n",res/(N-1));return 0;
}