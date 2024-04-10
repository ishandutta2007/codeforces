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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

int t,n;

int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int tmp=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return tmp;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n%111==0||n%11==0)
		{
			printf("yes\n");
			continue;
		}
		int x,y;exgcd(11,111,x,y);
		x*=n,y*=n;
		x=(x%111+111)%111;
		x=x==0?111:x;
		y=(n-11*x)/111;
		if(y<0)
			printf("no\n");
		else printf("yes\n");
	}
	return 0;
}