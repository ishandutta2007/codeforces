#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,M;vector<int>type[MAXN],deg[MAXN];const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y)
{
	if(type[x][y]==3)return;if(type[x][y])type[x][y]=3;
	For(k,0,3){int nx=x+dx[k],ny=y+dy[k];if(nx<1||nx>N||ny<1||ny>M||type[nx][ny]!=2)continue;deg[nx][ny]--;if(deg[nx][ny]<=1)dfs(nx,ny);}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)type[i].clear(),deg[i].clear(),type[i].resize(M+1),deg[i].resize(M+1);
		For(i,1,N)For(j,1,M){char c;cin>>c;type[i][j]=c=='L'?0:c=='#'?1:2;}
		For(i,1,N)For(j,1,M){For(k,0,3){int nx=i+dx[k],ny=j+dy[k];if(nx>=1&&nx<=N&&ny>=1&&ny<=M&&(type[nx][ny]==0||type[nx][ny]==2))deg[i][j]++;}}
		int x=0,y=0;For(i,1,N){For(j,1,M)if(!type[i][j]){x=i,y=j;break;}if(x||y)break;}
		dfs(x,y);For(i,1,N){For(j,1,M)cout<<(type[i][j]<=1?type[i][j]?'#':'L':type[i][j]==2?'.':'+');cout<<'\n';}
	}
	return 0;
}