#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,M,a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
	cin>>N>>M;For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c=='B';}For(i,1,N)For(j,1,M)b[i][j]=a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1];
	int sum=0,ans=0;For(i,1,N)For(j,1,M)sum+=b[i][j];ans=sum;
	For(i,1,N-1)For(j,1,M-1)ans=min(ans,sum-b[i][j]*2-b[i][M]*2-b[N][j]*2-b[N][M]*2+7);cout<<ans<<'\n';return 0;
}