#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int N,f[MAXN][4],id[MAXN];vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int p)
{
	vector<int>e;for(auto v:E[u])if(v.first!=p)e.push_back(v.first),id[v.first]=v.second,dfs(v.first,u);
	sort(e.begin(),e.end(),[&](int a,int b){return id[a]<id[b];});int M=e.size();vector<int>a(M),b(M),c(M);
	For(i,0,M-1)a[i]=(0ll+f[e[i]][0]+f[e[i]][1])%P,b[i]=(0ll+f[e[i]][2]+f[e[i]][3])%P,c[i]=(0ll+f[e[i]][0]+f[e[i]][2]+f[e[i]][3])%P;
	For(i,1,M-1)a[i]=1ll*a[i]*a[i-1]%P;FOR(i,M-2,0)c[i]=1ll*c[i]*c[i+1]%P;
	For(i,0,M-1)f[u][id[u]>id[e[i]]?0:2]=(f[u][id[u]>id[e[i]]?0:2]+1ll*(i?a[i-1]:1)*b[i]%P*(i<M-1?c[i+1]:1))%P;
	if(u!=1){f[u][1]=1;For(i,0,M-1)f[u][1]=1ll*f[u][1]*(id[u]>id[e[i]]?f[e[i]][0]+f[e[i]][1]:(0ll+f[e[i]][0]+f[e[i]][2]+f[e[i]][3]))%P;}
	f[u][3]=1;For(i,0,M-1)f[u][3]=1ll*f[u][3]*(f[e[i]][0]+f[e[i]][1])%P;
}
int main(){N=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back({v,i}),E[v].push_back({u,i});}dfs(1,0);cout<<(0ll+f[1][0]+f[1][2]+f[1][3])%P<<'\n';}