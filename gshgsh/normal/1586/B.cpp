#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,M;bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)vis[i]=0;
		For(i,1,M){int a=get(),b=get(),c=get();vis[b]=1;}
		For(i,1,N)if(!vis[i]){For(j,1,N)if(i!=j)cout<<i<<' '<<j<<'\n';break;}
	}
	return 0;
}