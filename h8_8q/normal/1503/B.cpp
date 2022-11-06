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
int n,a[N][N],id1x[N*N],id1y[N*N],id2x[N*N],id2y[N*N],k1,k2;

inline void tian(int a,int b,int c)
{
	printf("%lld %lld %lld\n",a,b,c);
	fflush(stdout);
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i+j)&1) k1++,id1x[k1]=i,id1y[k1]=j;
			else k2++,id2x[k2]=i,id2y[k2]=j;
	int n1=1,n2=1;
	for(int i=1;i<=n*n;++i)
	{
		int a=read();
		if(a==3)
		{
			if(n1<=k1)
				tian(1,id1x[n1],id1y[n1]),n1++;
			else tian(2,id2x[n2],id2y[n2]),n2++;
		}
		else if(a==1)
		{
			if(n2<=k2)
				tian(2,id2x[n2],id2y[n2]),n2++;
			else tian(3,id1x[n1],id1y[n1]),n1++;
		}
		else
		{
			if(n1<=k1)
				tian(1,id1x[n1],id1y[n1]),n1++;
			else tian(3,id2x[n2],id2y[n2]),n2++;
		}
	}
	return 0;
}