#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 401
int N,f[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();f[1][0]=f[1][1]=1;
	For(i,2,N)
	{
		f[i][0]=1;
		For(j,1,N)
		{
			For(k,0,j-1)f[i][j]=(f[i][j]+1ll*f[i-1][k]*f[i-1][j-1-k])%P;
			For(k,0,j)f[i][j]=(f[i][j]+1ll*f[i-1][k]*f[i-1][j-k])%P;
			For(k,0,j)f[i][j]=(f[i][j]+2ll*j*f[i-1][k]%P*f[i-1][j-k])%P;
			For(k,0,j+1)f[i][j]=(f[i][j]+1ll*j*(j+1)*f[i-1][k]%P*f[i-1][j+1-k])%P;
		}
	}
	cout<<f[N][1]<<'\n';
}