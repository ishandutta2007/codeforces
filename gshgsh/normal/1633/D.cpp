#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int T,N,M,a[MAXN],b[MAXN],dis[MAXN][MAXN],f[MAXN][MAXN*12];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	For(i,1,1000)For(j,1,1000)dis[i][j]=1e8*(i!=j);For(i,1,1000)For(j,1,i)if(i+i/j<=1000)dis[i][i+i/j]=1;
	For(k,1,1000)For(i,1,1000)if(dis[i][k]<1e5)For(j,1,1000)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	T=get();
	while(T--)
	{
		N=get(),M=min(get(),N*12);For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();For(i,0,N)For(j,0,M)f[i][j]=0;
		For(i,1,N){For(j,0,dis[1][a[i]]-1)f[i][j]=f[i-1][j];For(j,dis[1][a[i]],M)f[i][j]=max(f[i-1][j],f[i-1][j-dis[1][a[i]]]+b[i]);}
		cout<<f[N][M]<<'\n';
	}
	return 0;
}