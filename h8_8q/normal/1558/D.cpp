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
#define lc ch[x][0]
#define rc ch[x][1]
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

const int N=4e5+5,_LIM_=4e5,mod=998244353;
int t,n,m,a[N],jc[N],inv[N],tag[N];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=300000;x+=lowbit(x))
			c[x]+=v;
	}
	inline int query(int x)
	{
		int res=0;
		for(int i=(1<<18);i>=1;i>>=1)
			if(x>c[res+i])
				x-=c[res+i],res+=i;
		return res+1;
	}
}sum;

set<int> hav;

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline void init()
{
	jc[0]=1;
	for(int i=1;i<=300000;++i)
		sum.add(i,1);
	for(int i=1;i<=_LIM_;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[_LIM_]=q_pow(jc[_LIM_],mod-2);
	for(int i=_LIM_-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}

signed main()
{
	srand(time(0));
	init();
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=m;++i)
			read(),a[i]=read();
		hav.clear();
		for(int i=m;i>=1;--i)
		{
			hav.insert(sum.query(a[i]+1));
			a[i]=sum.query(a[i]);
			sum.add(a[i],-1);
		}
		for(int i=1;i<=m;++i)
			sum.add(a[i],1);
		printf("%lld\n",C(n+n-hav.size()-1,n));
	}
	return 0;
}