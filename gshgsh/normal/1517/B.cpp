#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,K,a[MAXN][MAXN],ans[MAXN][MAXN];bool vis[MAXN][MAXN];struct A{int x,y,val;bool operator<(A a)const{return val<a.val;}}b[MAXN*MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;K=0;For(i,1,N)For(j,1,M)cin>>a[i][j],ans[i][j]=vis[i][j]=0,b[++K]={i,j,a[i][j]};sort(b+1,b+K+1);
		For(i,1,M)ans[b[i].x][i]=b[i].val,vis[b[i].x][b[i].y]=1;For(i,1,N){int k=1;For(j,1,M)if(!ans[i][j]){while(vis[i][k])k++;ans[i][j]=a[i][k++];}}
		For(i,1,N)For(j,1,M)cout<<ans[i][j]<<" \n"[j==M];
	}
	return 0;
}