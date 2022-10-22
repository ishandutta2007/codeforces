#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 601
int T,N,a[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N*2)For(j,1,N*2)a[i][j]=get();
		ll sum=0;For(i,N+1,N*2)For(j,N+1,N*2)sum+=a[i][j];
		cout<<sum+min(min(min(a[N+1][1],a[N+1][N]),min(a[N*2][1],a[N*2][N])),min(min(a[1][N+1],a[1][N*2]),min(a[N][N+1],a[N][N*2])))<<'\n';
	}
	return 0;
}