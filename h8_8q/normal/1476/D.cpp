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

const int N=3e5+5;
int t,n,sum[N][2];
char s[N];

inline int query(int l,int r,int p)
{
    return sum[r][p]-sum[l-1][p];
}

signed main()
{
	t=read();
    while(t--)
    {
        n=read();
        scanf("%s",s+1);
        for(int i=1;i<=n;++i)
        {
            sum[i][0]=sum[i-1][0];
            sum[i][1]=sum[i-1][1];
            if(s[i]=='R') sum[i][i%2]++;
        }
        for(int i=1;i<=n+1;++i)
        {
            int l=i,r=n,res=i-1,ans=1;
            while(l<=r)
            {
                if(query(i,mid,i%2)==(int)ceil((mid-i+1)/2.0) && \
                   query(i,mid,(i+1)%2)==0)
                    res=mid,l=mid+1;
                else r=mid-1;
            }
            ans+=res-i+1;
            l=1,r=i-1,res=i;
            while(l<=r)
            {
                if(query(mid,i-1,(i-1)%2)==0 && \
                   query(mid,i-1,i%2)==(i-mid)/2)
                    res=mid,r=mid-1;
                else l=mid+1;
            }
            ans+=(i-1)-res+1;
            printf("%lld ",ans);
        }
        printf("\n");
    }
	return 0;
}