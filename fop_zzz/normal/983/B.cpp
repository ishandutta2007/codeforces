#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)

using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
const int N=5050;
int n,dp[N][N],a[N][N],mx[N][N];
int main()
{
	n=read();
	For(i,1,n)	dp[i][0]=read();
	For(i,1,n)	For(j,1,n-i)
		dp[j][i]=dp[j][i-1]^dp[j+1][i-1];
	For(i,1,n)	For(j,i,n)	a[i][j]=dp[i][j-i];
	For(i,1,n)	mx[i][i]=a[i][i];
	For(i,1,n)	For(j,i+1,n)	mx[i][j]=max(mx[i][j-1],a[i][j]);
	For(j,1,n)	Dow(i,1,j-1)	mx[i][j]=max(mx[i][j],mx[i+1][j]);
	int Q=read();
	For(i,1,Q)
	{
		int l=read(),r=read();
		printf("%d\n",mx[l][r]);
	}
}