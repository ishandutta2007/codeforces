#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,M,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=0;For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();sort(a+1,a+N+1);sort(b+1,b+N+1);
		bool flag=1;For(i,1,N)if(b[i]<a[i]){flag=0;break;}
		int mx=0;For(i,1,N)mx=max(mx,b[i]-a[i]);if(mx>1||!flag)cout<<"NO\n";else cout<<"YES\n";
	}
	return 0;
}