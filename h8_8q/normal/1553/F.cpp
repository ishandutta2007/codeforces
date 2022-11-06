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

const int N=3e5+5,BLOCK=1000;
int n,a[N],p[N],sum[BLOCK+5],num[BLOCK+5];

struct BIT
{
	int c[N];
	void add(int x,int v)
	{
		for(;x<=300000;x+=lowbit(x))
			c[x]+=v;
	}
	int sum(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	int query(int l,int r)
	{
		if(l>r) return 0;
		return sum(r)-sum(l-1);
	}
}s1,s2;

signed main()
{
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	int mx=-1;
	for(int i=1;i<=n;++i)
	{
		p[i]=p[i-1];
		if(a[i]<=BLOCK) sum[a[i]]++;
		else s1.add(a[i],1),s2.add(a[i],a[i]);
		for(int j=1;j<=BLOCK;++j)
		{
			p[i]+=sum[j]*(a[i]%j);
			num[j]+=a[i]%j;
		}
		int SUM=0,l,r;
		for(l=BLOCK+1;l<=a[i];l=r+1)
		{
			r=a[i]/(a[i]/l);++SUM;
			p[i]+=s1.query(l,r)*a[i]-s2.query(l,r)*(a[i]/l);
		}
		p[i]+=s1.query(l,300000)*a[i];
		if(a[i]<=BLOCK)
			p[i]+=num[a[i]];
		else
		{
			for(int j=1;j<=BLOCK;++j)
				p[i]+=sum[j]*(j%a[i]);
			int now=300001;
			while(now-1>BLOCK)
			{
				int l=BLOCK+1,r=now-1;
				int ned=r/a[i],ps=-1;
				while(l<=r)
				{
					if(mid/a[i]==ned)
						ps=mid,r=mid-1;
					else l=mid+1;
				}
				p[i]+=s2.query(ps,now-1)-s1.query(ps,now-1)*a[i]*ned;
				now=ps;++SUM;
			}
		}
		//mx=max(mx,SUM);
		printf("%lld ",p[i]);
	}
	//printf("%lld\n",mx);
	return 0;
}