#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 300001
int N,M,x,l,r,ans[MAXN];ll a[MAXN];bool vis[MAXN];vector<Pair>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u){vis[u]=1;for(auto i:E[u])if(!vis[i.F]){dfs(i.F);if(a[u]+a[i.F]>=x)a[u]+=a[i.F]-x,ans[++l]=i.S;else ans[--r]=i.S;}}
int main()
{
	N=get(),M=get(),x=get();ll sum=0;For(i,1,N)sum+=a[i]=get();if(sum<1ll*x*(N-1)){cout<<"NO\n";return 0;}
	For(i,1,M){int u=get(),v=get();E[u].push_back({v,i}),E[v].push_back({u,i});}l=0,r=N;dfs(1);cout<<"YES\n";For(i,1,N-1)cout<<ans[i]<<endl;return 0;
}