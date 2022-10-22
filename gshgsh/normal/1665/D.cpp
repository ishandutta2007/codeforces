#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int a,int b){cout<<"? "<<a<<' '<<b<<endl;return get();}
int main()
{
	int T=get();
	while(T--)
	{
		int ans=0,now=0;
		For(i,0,29)
		{
			int x=ask(now+(1<<i),now+(1<<(i+1))+(1<<i));
			if(!(x>>i&1))ans|=1<<i,now-=1<<i;
		}
		cout<<"! "<<ans<<endl;
	}
}