#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,sum[MAXN][20];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int N=MAXN-1;For(j,0,19)For(i,1,N)sum[i][j]=sum[i-1][j]+(!((i>>j)&1));T=get();
	while(T--)
	{
		int l=get(),r=get(),ans=r-l;For(j,0,19)ans=min(ans,sum[r][j]-sum[l-1][j]);
		cout<<ans<<'\n';
	}
}