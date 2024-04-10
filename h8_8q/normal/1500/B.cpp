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
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=1e6+5;
int n,m,k,q,A[N],B[N],C[N],ans,XX,YY,DD,p1,p2,p3;

inline bool check(int x);
inline int exgcd(int a,int b,int &x,int &y);

signed main()
{
	//freopen("yangli.in","r",stdin);
	n=read();m=read();k=read();
	DD=exgcd(n,-m,XX,YY);
	p1=abs(m/DD),p2=abs(n/DD),p3=abs(n*m/DD);
	for(int i=1;i<=n;++i) A[read()]=i;
	for(int i=1;i<=m;++i) B[read()]=i;
	for(int i=1;i<=max(n,m)*2;++i)
		if(A[i]&&B[i]) C[++q]=i;
	int l=0,r=5e17;
	while(l<=r)
	{
		if(check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}

inline bool check(int X)
{
	register int res=0;
	for(register int i=1;i<=q;++i)
	{
		register int a=n,b=-m,c=B[C[i]]-A[C[i]];
		register int x=XX,y=YY,d=DD;
		if(c%d!=0) continue;
		x*=c/d;y*=c/d;
		int num1=0,num2=1e18;
		if(x<0) num1=max(num1,ceil((-x+0.0)/p1));
		if(y<0) num1=max(num1,ceil((-y+0.0)/p2));
		x+=num1*p1;
		y+=num1*p2;
		num1=1e18;
		num1=min(num1,-x/p1);
		num1=min(num1,-y/p2);
		if(num1!=1e18)
		{
			x+=num1*p1;
			y+=num1*p2;
		}
		if(x*n+A[C[i]]>X||y*m+B[C[i]]>X) continue;
		num2=min(num2,(X-x*n-A[C[i]])/p3);
		num2=min(num2,(X-y*m-B[C[i]])/p3);
		res+=num2+1;
	}
	return X-res>=k;
}

inline int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;y=0;
		return a;
	}
	int tmp=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return tmp;
}