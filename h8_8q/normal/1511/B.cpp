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

int t,a,b,c;

int pri[15]={0,1,13,137,1373,12281,122777,1226959,12255871,122420729};

signed main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();c=read();
		if(a==b&&b==c)
		{
			for(int i=1;i<=a;++i)
				printf("1");
			printf(" ");
			for(int i=1;i<=b;++i)
				printf("1");
			printf("\n");
			continue;
		}
		if(a==c||b==c)
		{
			printf("1");
			for(int i=2;i<=a;++i)
				printf("0");
			printf(" 1");
			for(int i=2;i<=b;++i)
				printf("0");
			printf("\n");
			continue;
		}
		if(a==b)
		{
			printf("%lld",pri[a-c+1]);
			for(int i=1;i<=c-1;++i) printf("0");
			printf(" ");
			printf("%lld",pri[b-c]);
			printf("2");
			for(int i=1;i<=c-1;++i) printf("0");
			printf("\n");
			continue;
		}
		printf("%lld",pri[a-c+1]);
		for(int i=1;i<=c-1;++i) printf("0");
		printf(" ");
		printf("%lld",pri[b-c+1]);
		for(int i=1;i<=c-1;++i) printf("0");
		printf("\n");
	}
	return 0;
}