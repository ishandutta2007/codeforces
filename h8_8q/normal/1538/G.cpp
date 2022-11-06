#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

int t,a,b,x,y;

signed main()
{
	t=read();
	while(t--)
	{
		x=read();y=read();a=read();b=read();
		if(a<b) swap(a,b);
		int l=0,r=x/b,res1=0;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			int l1=0,r1=mid,res2=0;
			while(l1<=r1)
			{
				int mid2=((l1+r1)>>1);
				if(mid2*a+(mid-mid2)*b<=x)
					res2=mid2,l1=mid2+1;
				else r1=mid2-1;
			}
			if(res2*b+(mid-res2)*a<=y)
				res1=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",res1);
	}
	return 0;
}