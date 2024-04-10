#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int T,N,H,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),H=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1,greater<int>());
		int x=H/(a[2]+a[1])*2;H%=a[1]+a[2];if(H)if(H<=a[1])x++;else x+=2;
		cout<<x<<'\n';
	}
	return 0;
}