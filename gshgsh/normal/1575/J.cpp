#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,M,K,a[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int solve(int x){int u=1,v=x;while(u<=N){if(a[u][v]==1)a[u][v++]=2;else if(a[u][v]==3)a[u][v--]=2;else u++;}return v;}
int main()
{
	N=get(),M=get(),K=get();For(i,1,N)For(j,1,M)a[i][j]=get();
	For(i,1,K)cout<<solve(get())<<" \n"[i==K];return 0;
}