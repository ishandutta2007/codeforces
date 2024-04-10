#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
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
		N=get(),K=get();
		For(i,1,N)a[i]=get();ll ans=0;For(i,1,N)ans+=a[i];
		For(i,1,N)a[i]-=N-i;sort(a+1,a+N+1,greater<int>());
		For(i,1,K)ans-=a[i];cout<<ans-1ll*K*(K-1)/2<<'\n';
	}
}