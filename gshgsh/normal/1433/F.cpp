#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 71
int N,M,K,a[MAXN][MAXN],f[MAXN][MAXN][MAXN][MAXN];
int dfs(int x,int y,int cnt,int sum)
{
	if(f[x][y][cnt][sum]!=-INF)return f[x][y][cnt][sum];if(x==0)return sum?-INF:0;if(y==0)return f[x][y][cnt][sum]=dfs(x-1,M,M/2,sum);
	if(cnt)f[x][y][cnt][sum]=a[x][y]+dfs(x,y-1,cnt-1,(sum-a[x][y]%K+K)%K);return f[x][y][cnt][sum]=max(f[x][y][cnt][sum],dfs(x,y-1,cnt,sum));
}
int main(){cin>>N>>M>>K;For(i,0,N)For(j,0,M)For(k,0,M)For(l,0,K-1)f[i][j][k][l]=-INF;For(i,1,N)For(j,1,M)cin>>a[i][j];int ans=0;For(i,0,M/2)ans=max(ans,dfs(N,M,i,0));cout<<ans<<endl;return 0;}