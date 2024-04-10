#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

#define int long long
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}
template<typename T,typename TT> inline T Min(T a,TT b){return a>b?b:a;}
template<typename T> inline T Abs(T x){return x<0?-x:x;}

const int N=1e5+5;
int t,n,k,a[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int ans=1e18;
		for(int c=1;c<=100;++c)
		{
			int now=1,res=0;
			while(now<=n)
			{
				while(a[now]==c&&now<=n) now++;
				if(now<=n) now+=k,res++;
			}
			ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}