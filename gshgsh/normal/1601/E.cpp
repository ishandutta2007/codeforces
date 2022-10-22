#include<algorithm>
#include<iostream>
#include<cassert>
#include<random>
#include<vector>
#include<cstdio>
#include<deque>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int N,Q,K,a[MAXN],mn[MAXN][20],c[MAXN],f[MAXN][20];ll sum[MAXN][20];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int l,int r){int k=log2(r-l+1);return min(mn[l][k],mn[r-(1<<k)+1][k]);}
int main()
{
	N=get(),Q=get(),K=get();For(i,1,N)a[i]=get();
	For(i,1,N)mn[i][0]=a[i];for(int j=1;1<<j<=N;j++)For(i,1,N-(1<<j)+1)mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);For(i,1,N)c[i]=ask(i,min(i+K,N));For(i,0,19)f[N+1][i]=N+1;
	FOR(i,N,1){f[i][0]=i+K;if(f[i][0]>N)f[i][0]=N+1;while(c[i]<c[f[i][0]])f[i][0]=f[f[i][0]][0];sum[i][0]=1ll*(f[i][0]-i+K-1)/K*c[i];}
	For(j,1,19)For(i,1,N)f[i][j]=f[f[i][j-1]][j-1],sum[i][j]=sum[i][j-1]+sum[f[i][j-1]][j-1];
	while(Q--)
	{
		int l=get(),r=get();ll ans=a[l];
		FOR(i,19,0)if(f[l][i]<=r)ans+=sum[l][i],l=f[l][i];ans+=1ll*(r-l)/K*c[l];cout<<ans<<'\n';
	}
}