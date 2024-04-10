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

signed main()
{
    t=read();
    while(t--)
    {
        n=read();k=read();
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;++i)
            a[i]=read();
        int flag=0;
        for(int i=1;;++i)
        {
            int now=1;
            while(now<=n&&a[now]>=a[now+1])
                ++now;
            if(now==n+1) break;
            else if(i==k)
            {
                printf("%lld\n",now);
                flag=1;break;
            }
            a[now]++;
        }
        if(!flag) printf("-1\n");
    }
	return 0;
}