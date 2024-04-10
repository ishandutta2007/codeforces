#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int T,N,a[MAXN];int GCD(int a,int b){return b?GCD(b,a%b):a;}bool cmp(int a,int b){return (a&1)!=(b&1)?(a&1)<(b&1):a<b;}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1,cmp);
		int ans=0;For(i,1,N)if(a[i]&1)For(j,i+1,N)ans+=GCD(a[i],a[j])>1;else ans+=N-i;cout<<ans<<endl;
	}
	return 0;
}