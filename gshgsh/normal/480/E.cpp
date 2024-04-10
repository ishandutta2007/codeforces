#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<deque>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 3001
int N,M,K,a[MAXN][MAXN],x[MAXN],y[MAXN],f[MAXN][MAXN],g[MAXN][MAXN],dp[MAXN][MAXN],ans[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='.'&&c!='X')c=getchar();return c=='.';}
bool check(int x,int l)
{
	deque<int>q1,q2;
	For(i,1,l-1){while(!q1.empty()&&f[x][q1.back()]>=f[x][i])q1.pop_back();q1.push_back(i);}
	For(i,1,l-1){while(!q2.empty()&&g[x][q2.back()]>=g[x][i])q2.pop_back();q2.push_back(i);}
	For(i,l,M)
	{
		while(!q1.empty()&&q1.front()<=i-l)q1.pop_front();while(!q2.empty()&&q2.front()<=i-l)q2.pop_front();
		while(!q1.empty()&&f[x][q1.back()]>=f[x][i])q1.pop_back();q1.push_back(i);
		while(!q2.empty()&&g[x][q2.back()]>=g[x][i])q2.pop_back();q2.push_back(i);
		if(f[x][q1.front()]+g[x][q2.front()]>=l+1)return 1;
	}
	return 0;
}
int main()
{
	N=get(),M=get(),K=get();For(i,1,N)For(j,1,M)a[i][j]=getc();For(i,1,K)x[i]=get(),y[i]=get(),a[x[i]][y[i]]=0;
	For(i,1,N)For(j,1,M)f[i][j]=a[i][j]?f[i-1][j]+1:0;FOR(i,N,1)For(j,1,M)g[i][j]=a[i][j]?g[i+1][j]+1:0;
	int mx=0;For(i,1,M)mx=max(mx,dp[1][i]=a[1][i]);For(i,1,N)mx=max(mx,dp[i][1]=a[i][1]);
	For(i,2,N)For(j,2,M)mx=max(mx,dp[i][j]=a[i][j]?min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1:0);
	FOR(i,K,1)
	{
		ans[i]=mx;a[x[i]][y[i]]=1;For(j,1,N)f[j][y[i]]=a[j][y[i]]?f[j-1][y[i]]+1:0;FOR(j,N,1)g[j][y[i]]=a[j][y[i]]?g[j+1][y[i]]+1:0;
		int l=mx,r=min(N,M),pos=mx;while(l<=r){int mid=l+r>>1;check(x[i],mid)?pos=mid,l=mid+1:r=mid-1;}mx=max(mx,pos);
	}
	For(i,1,K)cout<<ans[i]<<'\n';
}