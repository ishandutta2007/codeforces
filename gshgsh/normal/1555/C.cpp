#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[2][MAXN],pre[MAXN],suf[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(j,0,1)For(i,1,N)a[j][i]=get();pre[1]=a[1][1];For(i,2,N)pre[i]=pre[i-1]+a[1][i];suf[N]=a[0][N];FOR(i,N-1,1)suf[i]=suf[i+1]+a[0][i];suf[N+1]=0;
		int ans=2e9;For(i,1,N)ans=min(ans,max(pre[i-1],suf[i+1]));cout<<ans<<endl;
	}
	return 0;
}