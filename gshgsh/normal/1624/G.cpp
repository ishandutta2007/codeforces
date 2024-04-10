#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,M,f[MAXN],u[MAXN],v[MAXN],w[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,M)u[i]=get(),v[i]=get(),w[i]=get();int ans=(1<<30)-1;
		FOR(i,29,0)
		{
			For(j,1,N)f[j]=j;For(j,1,M)if((w[j]&(ans^1<<i))==w[j])f[getf(u[j])]=getf(v[j]);
			ans^=1<<i;For(j,2,N)if(getf(j)!=getf(1)){ans|=1<<i;break;}
		}
		cout<<ans<<'\n';
	}
	return 0;
}