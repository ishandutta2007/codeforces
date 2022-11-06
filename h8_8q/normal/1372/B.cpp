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

int t,n;

signed main()
{
	t=read();
    while(t--)
    {
        n=read();
        int res=1e18,x,y;
        for(int i=1;i*i<=n;++i)
            if(n%i==0)
            {
                if(i!=1)
                {
                    int tmp=(n/i)*(n/i*(i-1))/__gcd(n/i,n/i*(i-1));
                    if(tmp<res) res=tmp,x=n/i,y=n/i*(i-1);
                }
                if(n/i!=1)
                {
                    int tmp=i*i*(n/i-1)/__gcd(i,i*(n/i-1));
                    if(tmp<res) res=tmp,x=i,y=i*(n/i-1);
                }
            }
        printf("%lld %lld\n",x,y);
    }
	return 0;
}