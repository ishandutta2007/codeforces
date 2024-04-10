#include<bits/stdc++.h>
#define MN 30
#define mod 1000000007
#define ll long long
using namespace std;
ll n;
int m,f[65][35][35],s[65],num,g[35][35],A[35],B[35];
inline int Dec(int x,int y){return x<m?(x-y+m)%m:m;}
int main()
{
	cin>>n>>m;
	for(ll t=n;t;t/=m) s[++num]=t%m;
	for(int i=1;i<=m;++i) f[1][i][i]=1;
	for(int i=0;i<=m;++i) f[1][0][i]=1;
	for(int i=2;i<=num;++i)
	{
		for(int j=0;j<=m;++j) f[i][j][j]=1;
		for(int j=0;j<m;++j)
		{
			for(int a=0;a<=m;++a) for(int b=0;b<=m;++b) for(int c=0;c<=m;++c)
				g[a][c]=(g[a][c]+1LL*f[i-1][Dec(a,j)][Dec(b,j)]*f[i][b][c])%mod;
			for(int a=0;a<=m;++a) for(int b=0;b<=m;++b)
				f[i][a][b]=g[a][b],g[a][b]=0;
	//			f[i][a][b]? printf("f[%d][%d][%d]=%d\n",i,a,b,f[i][a][b]):0;
		}
	}
	for(int i=0;i<=m;++i) A[i]=1;
	for(int i=1;i<=num;++i)
	{
		int S=0;
		for(int j=i+1;j<=num;++j) S=(S+s[j])%m;
		for(;s[i];--s[i]) 
		{
			int dec=(S+s[i])%m;
			for(int a=0;a<=m;++a) for(int b=0;b<=m;++b)	
				B[b]=(B[b]+1LL*A[a]*f[i][Dec(a,dec)][Dec(b,dec)])%mod;
			for(int a=0;a<=m;++a) A[a]=B[a],B[a]=0;
		}
	}
	printf("%d\n",A[m]);
	return 0;
}