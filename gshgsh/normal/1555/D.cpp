#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M,a[MAXN],sum[MAXN][6],b[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,N){char c;cin>>c;a[i]=c-'a';}For(i,1,N)For(j,0,5)sum[i][j]=(sum[i-1][j]+(a[i]!=b[j][i%3]));
	For(i,1,M){int l=get(),r=get(),ans=N;For(j,0,5)ans=min(ans,sum[r][j]-sum[l-1][j]);cout<<ans<<'\n';}return 0;
}