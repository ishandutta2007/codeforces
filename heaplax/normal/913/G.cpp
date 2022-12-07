#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int a;
int mul(int a,int b,int mod)
{
	int res=0;
	while(b)
	{
		if(b&1)res=(res+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return res;
}
int mi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1)res=mul(res,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return res;
}
main()
{
	int T;re(T);
	while(T--)
	{
		re(a);
		int n=0;
		for(int i=a;i;i/=10)++n;
		for(int m=0,tp=1;;++m)
		{
			int x=a,mod=1ll<<(n+m);
			if(x%mod !=0 )x+=mod-x%mod;
			if(x%5 == 0)x+=mod;
			if(x%mod==0 && x%5!=0 && x-a<tp)
			{
				int y=x>>n+m;
				int t=0;
				if (y % 5 == 0) t = -1;
                if (y % 5 == 1) t = 0;
                if (y % 5 == 2) t = 1;
                if (y % 5 == 3) t = 3;
                if (y % 5 == 4) t = 2;
				int p5=5;
				for(int i=1;i<n+m;++i)
				{
					while(mi(2,t,p5*5)!=y%(p5*5))
						t+=p5/5*4;
					p5*=5;
				}
				printf("%lld\n",t+n+m);
				break;
			}
			a*=10;tp*=10;
		}
	}
}