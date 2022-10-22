#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,K,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get();
		FOR(i,30,0)
		{
			int cnt=0;For(j,1,N)cnt+=!(a[j]>>i&1);
			if(cnt<=K){For(j,1,N)a[j]|=1<<i;K-=cnt;}
		}
		int ans=a[1];For(i,2,N)ans&=a[i];cout<<ans<<'\n';
	}
}