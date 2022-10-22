#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define pb push_back
#define MAXN 100001
int T,N,l[MAXN],r[MAXN];ll f[MAXN][2];vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u,int p){for(auto v:E[u])if(v!=p)dfs(v,u),f[u][0]+=max(f[v][0]+abs(l[u]-l[v]),f[v][1]+abs(l[u]-r[v])),f[u][1]+=max(f[v][0]+abs(r[u]-l[v]),f[v][1]+abs(r[u]-r[v]));}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)l[i]=get(),r[i]=get(),E[i].clear(),f[i][0]=f[i][1]=0;For(i,1,N-1){int u=get(),v=get();E[u].pb(v),E[v].pb(u);}
		dfs(1,0);cout<<max(f[1][0],f[1][1])<<endl;
	}
	return 0;
}