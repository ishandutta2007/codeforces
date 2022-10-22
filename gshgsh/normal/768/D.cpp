#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
#define MAXM 10001
int N,M,Q;double f[MAXM][MAXN],g[MAXN];
int main()
{
	cin>>N>>Q;M=N;f[0][0]=1;For(i,1,M){For(j,1,N)f[i][j]=f[i-1][j-1]*(N-j+1)/N+f[i-1][j]*j/N;if(i==M&&f[i][N]<0.5)M++;}
	For(i,N,M)g[i]=f[i][N];while(Q--){double x;cin>>x,x/=2000;cout<<lower_bound(g+N,g+M+1,x)-g<<'\n';}return 0;
}