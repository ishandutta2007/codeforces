#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN];pair<int,int>f[MAXN][2];bool vis[MAXN][2];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void Print(int x,int y){if(x>1)Print(x-1,f[x][y].second);cout<<y<<' ';}
int main()
{
	N=get();For(i,1,N)a[i]=get();f[1][0]={MAXN,0},f[1][1]={-1,0};vis[1][0]=vis[1][1]=1;
	For(i,2,N)
	{
		f[i][0]={-1,0},f[i][1]={MAXN,0};
		if(a[i]>a[i-1]&&vis[i-1][0])f[i][0]=max(f[i][0],{f[i-1][0].first,0}),vis[i][0]=1;
		if(a[i]>f[i-1][1].first&&vis[i-1][1])f[i][0]=max(f[i][0],{a[i-1],1}),vis[i][0]=1;
		if(a[i]<a[i-1]&&vis[i-1][1])f[i][1]=min(f[i][1],{f[i-1][1].first,1}),vis[i][1]=1;
		if(a[i]<f[i-1][0].first&&vis[i-1][0])f[i][1]=min(f[i][1],{a[i-1],0}),vis[i][1]=1;
	}
	if(vis[N][0]){cout<<"YES\n";Print(N,0);return 0;}if(vis[N][1]){cout<<"YES\n";Print(N,1);return 0;}cout<<"NO\n";return 0;
}