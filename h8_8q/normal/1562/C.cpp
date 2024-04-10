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

const int N=2e4+5;
int t,n;
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		int lim=n/2,ok=0;
		for(int i=lim+1;i<=n&&!ok;++i)
			if(s[i]=='0')
			{
				printf("%lld %lld %lld %lld\n",1,i,1,i-1);
				ok=1;break;
			}
		for(int i=1;i<=lim&&!ok;++i)
			if(s[i]=='0')
			{
				printf("%lld %lld %lld %lld\n",i,n,i+1,n);
				ok=1;break;
			}
		if(!ok)
			printf("%lld %lld %lld %lld\n",1,lim,n-lim+1,n);
	}
	return 0;
}