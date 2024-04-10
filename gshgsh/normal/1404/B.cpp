#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a,b,da,db,rt,dep[MAXN];vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u,int f){dep[u]=dep[f]+1;for(auto v:E[u])if(v!=f)dfs(v,u);}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),a=get(),b=get(),da=get(),db=get();For(i,1,N)dep[i]=0,E[i].clear();
		For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
		dep[0]=-1;dfs(a,0);if(dep[b]<=da||da*2>=db){cout<<"Alice\n";continue;}
		rt=0;For(i,1,N)if(dep[i]>dep[rt])rt=i;dfs(rt,0);int mx=0;For(i,1,N)mx=max(mx,dep[i]);cout<<(da*2>=mx?"Alice\n":"Bob\n");
	}
	return 0;
}