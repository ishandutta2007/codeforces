#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,f[MAXN],tmp[MAXN],ans;vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get(),w=get();E[w].push_back({u,v});}
	For(i,1,100000)
	{
		for(auto j:E[i])ans=max(ans,tmp[j.second]=max(tmp[j.second],f[j.first]+1));
		for(auto j:E[i])f[j.second]=max(f[j.second],tmp[j.second]);
	}
	cout<<ans<<'\n';return 0;
}