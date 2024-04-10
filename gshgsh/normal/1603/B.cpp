#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int x=get(),y=get();
		if(x>y){cout<<1ll*x*y+y<<'\n';continue;}
		if(x==y){cout<<x<<'\n';continue;}
		int tmp=x;x*=y/x;if(x==y)x-=tmp;cout<<(y+x>>1)<<'\n';
	}
	return 0;
}