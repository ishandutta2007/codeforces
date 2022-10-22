#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 5001
int N,K,M,a[MAXN],f[MAXN][MAXN],g[MAXN];
int main()
{
	cin>>N>>K>>M;For(i,1,N)cin>>a[i],f[i][0]=1;For(j,1,K){f[1][j]=f[2][j-1];For(i,2,N-1)f[i][j]=(f[i-1][j-1]+f[i+1][j-1])%P;f[N][j]=f[N-1][j-1];}
	For(i,1,N)For(j,0,K)g[i]=(g[i]+1ll*f[i][j]*f[i][K-j])%P;int sum=0;For(i,1,N)sum=(sum+1ll*a[i]*g[i])%P;
	For(i,1,M){int x,y;cin>>x>>y;sum=(sum+1ll*(y-a[x]+P)*g[x])%P,a[x]=y;cout<<sum<<endl;}return 0;
}