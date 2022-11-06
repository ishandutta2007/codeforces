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

const int N=2e5+5;
int a,b,ta,tb,k,n;
char s[N],t[N];

signed main()
{
	a=read();b=read();k=read();
	if(k==0)
	{
		printf("Yes\n");
		for(int i=1;i<=b;++i)
			printf("1");
		for(int i=1;i<=a;++i)
			printf("0");
		printf("\n");
		for(int i=1;i<=b;++i)
			printf("1");
		for(int i=1;i<=a;++i)
			printf("0");
		printf("\n");
		return 0;
	}
	if(a+b<=k+1||b<2||a==0)
	{
		printf("No\n");
		return 0;
	}
	
	ta=a;tb=b;
	s[k+1]='1';tb--;s[1]='0';ta--;
	if(k+1!=a+b) s[a+b]='1';tb--;
	for(int i=2;i<=k;++i)
	{
		if(ta) s[i]='0',--ta;
		else if(tb) s[i]='1',--tb;
	}
	int now=k+1;
	while(ta)
	{
		s[++now]='0';
		ta--;
	}
	while(tb)
	{
		s[++now]='1';
		tb--;
	}
	
	ta=a;tb=b;
	t[1]='1';tb--;t[k+1]='0';ta--;
	if(k+1!=a+b) t[a+b]='1';tb--;
	for(int i=2;i<=k;++i)
	{
		if(ta) t[i]='0',--ta;
		else if(tb) t[i]='1',--tb;
	}
	now=k+1;
	while(ta)
	{
		t[++now]='0';
		ta--;
	}
	while(tb)
	{
		t[++now]='1';
		tb--;
	}
	printf("Yes\n");
	for(int i=a+b;i>=1;--i)
		printf("%c",s[i]);
	printf("\n");
	for(int i=a+b;i>=1;--i)
		printf("%c",t[i]);
	return 0;
}