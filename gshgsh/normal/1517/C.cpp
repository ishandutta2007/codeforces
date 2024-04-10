#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int N,a[MAXN],ans[MAXN][MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];
	For(i,1,N){int k=a[i];int x=i,y=i;while(k){ans[x][y]=a[i];k--;if(y>1&&!ans[x][y-1])y--;else x++;}}
	For(i,1,N)For(j,1,i)cout<<ans[i][j]<<" \n"[j==i];return 0;
}