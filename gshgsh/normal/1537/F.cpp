#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define pb push_back
#define MAXN 200001
int T,N,M,col[MAXN],a[MAXN],b[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool dfs(int u,int pre){col[u]=pre^1;for(auto v:E[u])if(col[v]==-1){if(!dfs(v,pre^1))return 0;}else if(col[u]==col[v])return 0;return 1;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get(),E[i].clear(),col[i]=-1;For(i,1,N)b[i]=get();For(i,1,M){int u=get(),v=get();E[u].pb(v),E[v].pb(u);}
		ll sum1=0,sum2=0;For(i,1,N)sum1+=a[i],sum2+=b[i];if(abs(sum1-sum2)&1){cout<<"NO\n";continue;}
		if(!dfs(1,0)){cout<<"YES\n";continue;}ll sum[2][2]={{0,0},{0,0}};For(i,1,N)sum[0][col[i]]+=a[i],sum[1][col[i]]+=b[i];
		cout<<(sum[0][0]-sum[0][1]==sum[1][0]-sum[1][1]?"YES\n":"NO\n");
	}
	return 0;
}