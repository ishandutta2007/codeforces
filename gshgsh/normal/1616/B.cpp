#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N){char c;cin>>c;a[i]=c;}
		int x=1;bool flag=0;For(i,2,N)if(a[i]<a[i-1])x=i,flag=1;else if(flag&&a[i]==a[i-1])x=i;else break;
		For(i,1,x)cout<<char(a[i]);FOR(i,x,1)cout<<char(a[i]);cout<<'\n';
	}
}