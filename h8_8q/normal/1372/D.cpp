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

const int N=4e5+5;
int n,a[N],sum1[N],sum2[N],ans;

signed main()
{
	n=read();
    for(int i=1;i<=n;++i)
        a[i]=a[n+i]=read();
    for(int i=1;i<=n*2;++i)
    {
        sum1[i]=sum1[i-1];
        sum2[i]=sum2[i-1];
        if(i%2==1) sum1[i]+=a[i];
        else sum2[i]+=a[i];
    }
    for(int i=1;i<=n;++i)
        if(i%2==1) ans=max(ans,sum1[n+i]-sum1[i-1]);
        else ans=max(ans,sum2[n+i]-sum2[i-1]);
    printf("%lld\n",ans);
	return 0;
}