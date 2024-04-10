#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,s) for(auto i:s)
#define INF (1<<30)
#define MAXN 200001
ll N[4],a[4][MAXN],f[MAXN],g[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	For(i,0,3)N[i]=get();For(i,0,3)For(j,1,N[i])a[i][j]=get();For(i,1,N[0])f[i]=a[0][i];
	For(i,1,3)
	{
		int M=get();vector<int>pos[MAXN];multiset<ll>mn;For(j,1,M){int x=get(),y=get();pos[y].push_back(x);}For(j,1,N[i-1])mn.insert(f[j]);
		For(j,1,N[i]){FOR(k,pos[j])mn.erase(mn.find(f[k]));g[j]=!mn.empty()?a[i][j]+(*mn.begin()):INF;FOR(k,pos[j])mn.insert(f[k]);}For(j,1,N[i])f[j]=g[j];
	}
	ll ans=INF;For(i,1,N[3])ans=min(ans,f[i]);cout<<(ans<INF?ans:-1)<<endl;return 0;
}