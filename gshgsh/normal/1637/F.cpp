#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN];ll ans;vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int dfs(int u,int f){int mx1=0,mx2=0;for(auto v:E[u])if(v!=f){int tmp=dfs(v,u);if(tmp>mx1)mx2=mx1,mx1=tmp;else mx2=max(mx2,tmp);}if(f)ans+=max(a[u]-mx1,0),mx1=max(mx1,a[u]);else ans+=max(a[u]-mx1,0)+max(a[u]-mx2,0);return mx1;}
int main()
{
	N=get();For(i,1,N)a[i]=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	int rt=1;For(i,2,N)if(a[i]>a[rt])rt=i;dfs(rt,0);cout<<ans<<'\n';return 0;
}