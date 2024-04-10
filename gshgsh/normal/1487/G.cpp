#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 501
int N,c[MAXN],f[2][MAXN][MAXN][3][3],g[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,26)c[i]=get();For(i,0,2)For(j,0,2)f[0][(i==0)+(j==0)][(i==1)+(j==1)][i][j]=(i==2?24:1)*(j==2?24:1);int lst=0,now=1;
	For(i,3,N)
	{
		For(a,0,N)For(b,0,N)For(j,0,2)For(k,0,2)f[now][a][b][j][k]=0;
		For(a,0,N)For(b,0,N)For(j,0,2)For(k,0,2)
		{
			if(j!=0)f[now][a+1][b][k][0]=(f[now][a+1][b][k][0]+f[lst][a][b][j][k])%P;
			if(j!=1)f[now][a][b+1][k][1]=(f[now][a][b+1][k][1]+f[lst][a][b][j][k])%P;
			f[now][a][b][k][2]=(f[now][a][b][k][2]+(23ll+(j!=2))*f[lst][a][b][j][k])%P;
		}
		swap(now,lst);
	}
	For(i,0,N)For(j,0,N)For(k,0,2)For(l,0,2)g[i][j]=(g[i][j]+f[lst][i][j][k][l])%P;
	FOR(i,N,0)FOR(j,N-1,0)g[i][j]=(g[i][j]+g[i][j+1])%P;FOR(i,N-1,0)FOR(j,N,0)g[i][j]=(g[i][j]+g[i+1][j])%P;
	int ans=g[0][0];For(i,1,26)ans=(ans-g[c[i]+1][0]+P)%P;For(i,1,26)For(j,i+1,26)ans=(ans+g[c[i]+1][c[j]+1])%P;cout<<ans<<'\n';
}