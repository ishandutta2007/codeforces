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
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=1e4+5;
int n,k,A[N],a[N],b[N],p1[N],c[N],p2[N];

inline int AND(int x,int y)
{
	//return (A[x]&A[y]);
	printf("and %lld %lld\n",x,y);
	fflush(stdout);return read();
}

inline int OR(int x,int y)
{
	//return (A[x]|A[y]);
	printf("or %lld %lld\n",x,y);
	fflush(stdout);return read();
}

signed main()
{
	n=read();k=read();
	//for(int i=1;i<=n;++i)
	//	A[i]=read();
	b[1]=AND(2,3);c[1]=OR(2,3);
	for(int i=2;i<=n;++i)
	{
		b[i]=AND(1,i);
		c[i]=OR(1,i);
	}
	for(int i=30;i>=0;--i)
	{
		for(int j=1;j<=n;++j)
		{
			p1[j]=((b[j]>>i)&1);
			p2[j]=((c[j]>>i)&1);
		}
		int flag=-1;
		for(int j=2;j<=n;++j)
			if(p1[j]==1) flag=1;
			else if(p2[j]==0) flag=0;
		if(flag==-1)
		{
			if(p2[1]==0)
				flag=1;
			else flag=0;
		}
		a[1]|=(flag<<i);
		if(flag==1)
		{
			for(int j=2;j<=n;++j)
				if(p1[j]==1)
					a[j]|=(1<<i);
		}
		else
		{
			for(int j=2;j<=n;++j)
				if(p2[j]==1)
					a[j]|=(1<<i);
		}
	}
	sort(a+1,a+1+n);
	printf("finish %lld\n",a[k]);
	return 0;
}