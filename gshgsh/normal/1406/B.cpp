#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 100001
int T,N,a[MAXN];ll f[MAXN][6],g[MAXN][6];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,N){if(i)a[i]=get();For(j,0,5)f[i][j]=i>=j?1:-INF,g[i][j]=i>=j?1:INF;}
		For(i,1,5)
		{
			For(j,i,N)f[j][i]=max(f[j-1][i],max(f[j-1][i-1]*a[j],g[j-1][i-1]*a[j]));
			For(j,i,N)g[j][i]=min(g[j-1][i],min(f[j-1][i-1]*a[j],g[j-1][i-1]*a[j]));
		}
		cout<<f[N][5]<<endl;
	}
	return 0;
}