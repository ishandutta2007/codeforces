#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 100001
int T,N,M,K,x,y,a[MAXN],f[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
char getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),K=get();For(i,1,N)a[i]=getc()-'0';x=get(),y=get();For(i,N-K+1,N)f[i]=1-a[i];FOR(i,N-K,1)f[i]=f[i+K]+1-a[i];
		ans=INF;For(i,M,N)ans=min(ans,y*(i-M)+x*f[i]);cout<<ans<<endl;
	}
	return 0;
}