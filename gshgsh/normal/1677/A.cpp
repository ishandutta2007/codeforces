#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 5001
int T,N,p[MAXN],sum[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)p[i]=get();For(i,1,N)For(j,1,N)sum[i][j]=0;
		For(i,1,N)sum[i][p[i]]=1;For(i,1,N)For(j,1,N)sum[i][j]+=sum[i][j-1];For(i,1,N)For(j,1,N)sum[i][j]+=sum[i-1][j];
		ll ans=0;For(i,2,N-1)For(j,i+1,N-1)ans+=sum[i-1][p[j]-1]*(sum[N][p[i]-1]-sum[j][p[i]-1]);cout<<ans<<'\n';
	}
}