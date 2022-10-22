#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int T,N,M,dep[MAXN],f[MAXN];bool vis[MAXN];vector<int>E[MAXN],E2[MAXN],id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u){vis[u]=1;for(auto v:E[u])if(!vis[v])E2[u].push_back(v),f[v]=u,dep[v]=dep[u]+1,dfs(v);}
void solve1(){For(i,1,N)if(dep[i]>=N+1>>1){cout<<"PATH\n"<<dep[i]<<'\n';while(i)cout<<i<<' ',i=f[i];cout<<'\n';break;}}
void solve2(){For(i,1,N)id[i].clear();For(i,1,N)id[dep[i]].push_back(i);int cnt=(N+1>>1)+1>>1,i=1;cout<<"PAIRING\n"<<cnt<<'\n';while(cnt){while(id[i].size()<2)i++;cout<<id[i].back()<<' ';id[i].pop_back();cout<<id[i].back()<<'\n';id[i].pop_back();cnt--;}}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)vis[i]=0,E[i].clear(),E2[i].clear();
		For(i,1,M){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}dep[1]=1;dfs(1);
		int K=1;For(i,2,N)K=max(K,dep[i]);if(K>=N+1>>1)solve1();else solve2();
	}
	return 0;
}