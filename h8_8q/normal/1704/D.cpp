#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

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

const int N=1e6+5;
int t,n,m,c[N],d2[N];

#define id(x,y) (((x)-1)*m+(y))

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				c[id(i,j)]=read();
		for(int i=1;i<=m;++i)
			d2[i]=c[id(2,i)];
		int ps1=-1,ps2=-1,nm=0;
		for(int i=1;i<=n;++i)
		{
			int l=0,r=0;
			for(int j=1;j<m;++j)
				if(c[id(i,j)]>c[id(1,j)])
				{
					int tmp=c[id(i,j)]-c[id(1,j)];
					l+=tmp;c[id(i,j)]-=tmp;c[id(i,j+1)]+=tmp;
				}
			for(int j=m;j>1;--j)
				if(c[id(i,j)]>c[id(1,j)])
				{
					int tmp=c[id(i,j)]-c[id(1,j)];
					r+=tmp;c[id(i,j)]-=tmp;c[id(i,j-1)]+=tmp;
				}
			if(l==r) nm++;
			if(l!=r) ps1=i,ps2=r-l;
		}
		if(nm!=n-1)
		{
			ps1=1;
			int l=0,r=0;
			for(int j=1;j<m;++j)
				if(c[id(1,j)]>d2[j])
				{
					int tmp=c[id(1,j)]-d2[j];
					l+=tmp;c[id(1,j)]-=tmp;c[id(1,j+1)]+=tmp;
				}
			for(int j=m;j>1;--j)
				if(c[id(1,j)]>d2[j])
				{
					int tmp=c[id(1,j)]-d2[j];
					r+=tmp;c[id(1,j)]-=tmp;c[id(1,j-1)]+=tmp;
				}
			ps2=r-l;
			write(ps1),putchar(' '),write(ps2),puts("");
		}
		else write(ps1),putchar(' '),write(ps2),puts("");
	}
	return 0;
}