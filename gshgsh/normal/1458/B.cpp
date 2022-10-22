#include<iostream>
#include<cstring>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 101
int N,a[MAXN],b[MAXN],A[MAXN],B,f[MAXN][MAXN][MAXN*MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i]>>b[i],A[i]=A[i-1]+a[i],B+=b[i];For(i,0,N)For(j,0,N)For(k,0,A[N])f[i][j][k]=-INF;f[0][0][0]=0;
	For(i,1,N)For(j,0,i)For(k,0,A[i])f[i][j][k]=max(f[i-1][j][k],j&&k>=a[i]?f[i-1][j-1][k-a[i]]+b[i]:-INF);
	For(i,1,N){double ans=0;For(j,0,A[N])ans=max(ans,min(j*1.0,f[N][i][j]/2.0+B/2.0));cout<<ans<<endl;}return 0;
}