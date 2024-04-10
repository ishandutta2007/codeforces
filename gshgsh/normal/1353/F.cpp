#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffffffffffff
#define MAXN 101
int T,N,M;ll a[MAXN][MAXN],f[MAXN][MAXN];
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)For(j,1,M)a[i][j]=get();ll ans=INF;
		For(x,1,N)For(y,1,M)
		{
			ll a0=a[x][y]-x-y;f[1][1]=a[1][1]-2-a0;if(f[1][1]<0)continue;
			For(i,2,N)f[i][1]=f[i-1][1]!=INF&&a[i][1]-i-1>=a0?f[i-1][1]+a[i][1]-i-1-a0:INF;
			For(i,2,M)f[1][i]=f[1][i-1]!=INF&&a[1][i]-1-i>=a0?f[1][i-1]+a[1][i]-1-i-a0:INF;
			For(i,2,N)For(j,2,M){f[i][j]=INF;if(a[i][j]-i-j<a0)continue;if(f[i-1][j]!=INF||f[i][j-1]!=INF)f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j]-i-j-a0;}ans=min(ans,f[N][M]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}