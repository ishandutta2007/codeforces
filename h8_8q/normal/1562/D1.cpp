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

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
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

const int N=3e5+5;
int t,n,q,sum1[N],sum2[N];
char s[N];

struct Seg
{
	int val[N*40],lc[N*40],rc[N*40],rt[N],cnt;
	inline void clear()
	{
		for(int i=1;i<=cnt;++i)
			val[i]=0,lc[i]=0,rc[i]=0;
		for(int i=0;i<=n;++i)
			rt[i]=0;
		cnt=0;
	}
	void update(int &x,int y,int l,int r,int p,int v)
	{
		if(!x) x=++cnt;
		if(l==r){val[x]=val[y]+v;return;}
		if(p<=mid) update(lc[x],lc[y],l,mid,p,v),rc[x]=rc[y];
		else update(rc[x],rc[y],mid+1,r,p,v),lc[x]=lc[y];
		val[x]=val[lc[x]]+val[rc[x]];
	}
	int query(int x,int l,int r,int p)
	{
		if(!x) return 0;
		if(l==r) return val[x];
		if(p<=mid) return query(lc[x],l,mid,p);
		else return query(rc[x],mid+1,r,p);
	}
}s1,s2;

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();q=read();
		s1.clear();s2.clear();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
		{
			int tmp=(s[i]=='+'?1:-1);
			if(i%2==1)
			{
				sum1[i]=sum1[i-1]+tmp;
				sum2[i]=sum2[i-1]-tmp;
			}
			else
			{
				sum1[i]=sum1[i-1]-tmp;
				sum2[i]=sum2[i-1]+tmp;
			}
		}
		for(int i=1;i<=n;++i)
		{
			s1.update(s1.rt[i],s1.rt[i-1],-2*n,2*n,sum1[i]+sum1[i-1],1);
			s2.update(s2.rt[i],s2.rt[i-1],-2*n,2*n,sum2[i]+sum2[i-1],1);
		}
		while(q--)
		{
			int l=read(),r=read();
			if(l%2==1)
			{
				if(sum1[r]-sum1[l-1]==0)
					printf("0\n");
				else
				{
					if(s1.query(s1.rt[r],-2*n,2*n,sum1[r]+sum1[l-1])-s1.query(s1.rt[l-1],-2*n,2*n,sum1[r]+sum1[l-1])!=0)
						printf("1\n");
					else printf("2\n");
				}
			}
			else
			{
				if(sum2[r]-sum2[l-1]==0)
					printf("0\n");
				else
				{
					if(s2.query(s2.rt[r],-2*n,2*n,sum2[r]+sum2[l-1])-s2.query(s2.rt[l-1],-2*n,2*n,sum2[r]+sum2[l-1])!=0)
						printf("1\n");
					else printf("2\n");
				}
			}
		}
	}
	return 0;
}