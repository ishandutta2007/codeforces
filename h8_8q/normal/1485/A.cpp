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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

int t,a,b;

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c;
		a=a*a;b>>=1;
	}
	return c;
}

inline bool check(int a,int b,int p)
{
	int c=1,tag=0;
	while(b)
	{
		if(b&1)
		{
			c=a*c;
			if(tag) return 1;
		}
		if(c>p) return 1;
		a=a*a;
		if(a>p) tag=1;
		b>>=1;
	}
	return 0;
}

signed main()
{
	t=read();
    while(t--)
    {
        a=read();b=read();
        if(a<b)
        {
        	printf("1\n");
        	continue;
		}
		if(a==b)
		{
			printf("2\n");
			continue;
		}
        int res=1e18,flag=0;
        if(b==1) b++,flag=1;
        for(int i=1;q_pow(b,i)<=a;++i)
        {
        	if(q_pow(b,i+1)>a) res=min(res,i+1+flag);
        	int l=0,r=a,tmp=0;
        	while(l<=r)
        	{
        		if(check(b+mid,i,a))
        			tmp=mid,r=mid-1;
        		else l=mid+1;
			}
			res=min(res,i+tmp+flag);
		}
		printf("%lld\n",res);
    }
	return 0;
}