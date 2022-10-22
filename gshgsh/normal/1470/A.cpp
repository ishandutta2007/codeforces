#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,M,a[MAXN],b[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1,greater<int>());For(i,1,M)b[i]=get();
		ll ans=0;int j=0;For(i,1,N)j++,ans+=a[i]>=j?b[j]:b[a[i]];cout<<ans<<endl;
	}
	return 0;
}