#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,x,a[MAXN];bool vis[MAXN];map<int,vector<int>>ssh;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
signed main()
{
	T=get();
	while(T--)
	{
		N=get(),x=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);ssh.clear();For(i,1,N)ssh[a[i]].push_back(i);
		int ans=N;For(i,1,N)vis[i]=0;
		For(i,1,N)if(!vis[i]){if(ssh[a[i]*x].size())ans-=2,vis[i]=1,vis[ssh[a[i]*x].back()]=1,ssh[a[i]*x].pop_back();}
		cout<<ans<<'\n';
	}
	return 0;
}