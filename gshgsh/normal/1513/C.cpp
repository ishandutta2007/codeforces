#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int T,N,M,f[MAXN][10];
int main()
{
	N=MAXN-1;f[0][9]=1;For(i,1,N)For(j,0,9)f[i][j]=j==0?f[i-1][9]:j==1?(f[i-1][9]+f[i-1][0])%P:f[i-1][j-1];cin>>T;
	while(T--)
	{
		scanf("%d%d",&N,&M);int ans=0;
		while(N){int x=N%10;if(9-x<=M){For(i,0,9)ans=(ans+f[M-9+x][i])%P;}else ans=(ans+1)%P;N/=10;}
		printf("%d\n",ans);
	}
	return 0;
}