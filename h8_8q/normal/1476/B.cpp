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

const int N=105;
int t,n,k,a[N];

inline bool check(int x);

signed main()
{
	t=read();
    while(t--)
    {
        n=read();k=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        int l=0,r=1e12,ans=0;
        while(l<=r)
        {
            if(check(mid))
                ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
	return 0;
}

inline bool check(int x)
{
    int now=a[1]+x;
    for(int i=2;i<=n;++i)
    {
        if(100*a[i]>now*k)
            return 0;
        now+=a[i];
    }
    return 1;
}