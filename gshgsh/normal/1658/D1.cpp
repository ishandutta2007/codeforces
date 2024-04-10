#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<17
int T,N,cnt[17];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		get(),N=get()+1;For(i,0,16)cnt[i]=0;For(i,0,N-1){int x=get();For(j,0,16)cnt[j]+=x>>j&1;}
		int ans=0;For(i,0,16)if(cnt[i]*2>N)ans|=1<<i;cout<<ans<<'\n';
	}
}