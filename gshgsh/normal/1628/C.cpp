#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int T,N,a[MAXN][MAXN];bool vis[MAXN][MAXN];const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void solve(int x,int y){For(k,0,3){int nx=x+dx[k],ny=y+dy[k];if(nx>=1&&nx<=N&&ny>=1&&ny<=N)vis[nx][ny]=1;}}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)For(j,1,N)a[i][j]=get(),vis[i][j]=0;int ans=0;
		For(i,1,N)if((i-1&3)==1)solve(1,i),ans^=a[1][i];
		For(i,2,N)For(j,1,N)if((i+j&1)&&!vis[i-1][j])solve(i,j),ans^=a[i][j];
		For(i,1,N)if((i-1&3)==2)solve(1,i),ans^=a[1][i];
		For(i,2,N)For(j,1,N)if(!(i+j&1)&&!vis[i-1][j])solve(i,j),ans^=a[i][j];
		cout<<ans<<'\n';
	}
	return 0;
}