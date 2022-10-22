#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
#define MAXM 2000001
int N,M,a[MAXN],dep[MAXN],tot,prm[MAXM];pair<int,int>ans[MAXN];bool Not[MAXM];vector<int>E[MAXN],Div[MAXM];vector<pair<int,int>>s[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f)
{
	ans[u]={0,-1};for(auto i:Div[a[u]]){if(!s[i].empty())ans[u]=max(ans[u],s[i].back());}
	dep[u]=dep[f]+1;for(auto i:Div[a[u]])s[i].push_back({dep[u],u});
	for(auto v:E[u])if(v!=f)dfs(v,u);for(auto i:Div[a[u]])s[i].pop_back();
}
int main()
{
	For(i,2,MAXM-1){if(!Not[i])prm[++tot]=i;for(int j=1;j<=tot&&i*prm[j]<MAXM;j++){Not[i*prm[j]]=1;if(i%prm[j]==0)break;}}
	For(i,1,tot)for(int j=prm[i];j<MAXM;j+=prm[i])Div[j].push_back(i);
	N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);For(i,1,M){int opt=get(),x=get();if(opt==1)cout<<ans[x].second<<'\n';else a[x]=get(),dfs(1,0);}return 0;
}