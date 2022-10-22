#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 5001
int N,f[MAXN][MAXN][2];ll x[MAXN],t[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)t[i]=get(),x[i]=get();memset(f,0x7f,sizeof(f));f[0][0][0]=0;
	For(i,0,N)For(j,0,N)For(k,0,1)if(f[i][j][k]<0x7f7f7f7f)
	{
		if(i==N||(i==N-1&&j==N)){cout<<"YES\n";return 0;}int u=k?j:i,v=i+1+(j==i+1);if(v<=N&&abs(x[v]-x[u])+f[i][j][k]<=t[v])f[v][j*(j>v)][0]=min(1ll*f[v][j*(j>v)][0],t[v]);
		if(j==i||j==i+1)For(l,j+1,N)if(max(f[i][j][k]+abs(x[l]-x[u]),t[j])<=t[l])f[j][l][1]=min(1ll*f[j][l][1],max(f[i][j][k]+abs(x[l]-x[u]),t[j]));
	}
	cout<<"NO\n";return 0;
}