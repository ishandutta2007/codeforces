#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 501
#define MAXK 11
int N,M,K,a[MAXN][MAXN],b[MAXN][MAXN],f[MAXN][MAXN][MAXK];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get(),K=get();if(K&1){For(i,1,N)For(j,1,M)cout<<-1<<" \n"[j==M];return 0;}For(i,1,N)For(j,1,M-1)a[i][j]=get();For(i,1,N-1)For(j,1,M)b[i][j]=get();
	For(k,1,K/2)For(i,1,N)For(j,1,M)
	{
		f[i][j][k]=INF;if(j>1)f[i][j][k]=min(f[i][j][k],f[i][j-1][k-1]+a[i][j-1]);if(j<M)f[i][j][k]=min(f[i][j][k],f[i][j+1][k-1]+a[i][j]);
		if(i>1)f[i][j][k]=min(f[i][j][k],f[i-1][j][k-1]+b[i-1][j]);if(i<N)f[i][j][k]=min(f[i][j][k],f[i+1][j][k-1]+b[i][j]);
	}
	For(i,1,N)For(j,1,M)cout<<f[i][j][K/2]*2<<" \n"[j==M];return 0;
}