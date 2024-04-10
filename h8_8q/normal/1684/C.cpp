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

const int N=4e5+5;
int t,n,m,a[N];

#define id(x,y) (((x)-1)*m+(y))

inline bool check()
{
	for(int i=1;i<=n;++i)
		for(int j=2;j<=m;++j)
			if(a[id(i,j)]<a[id(i,j-1)])
				return 0;
	return 1;
}

inline void work(int x,int y)
{
	for(int i=1;i<=n;++i)
		swap(a[id(i,x)],a[id(i,y)]);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[id(i,j)]=read();
		if(check())
		{
			puts("1 1");
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					a[id(i,j)]=0;
			continue;
		}
		int nm=0,pp=0;
		for(int j=1;j<=n;++j)
		{
			for(int i=1;i<m;++i)
				if(a[id(j,i)]>a[id(j,i+1)])
					nm++;	
			if(nm)
			{
				pp=j;
				break;
			}
		}
		if(nm>=3)
		{
			puts("-1");
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					a[id(i,j)]=0;
			continue;
		}
		int p1=-1,nn=0;
		for(int i=1;i<m;++i)
			if(a[id(pp,i)]>a[id(pp,i+1)])
			{
				p1=i;
				break;
			}
		if(nm==1)
		{
			int ps=m+1;
			for(int i=p1+1;i<=m;++i)
				if(a[id(pp,i)]!=a[id(pp,p1+1)])
				{
					ps=i;
					break;
				}
			work(p1,ps-1);
			if(check())
			{
				write(p1);putchar(' ');
				write(ps-1);puts("");
			}
			else
			{
				work(p1,ps-1);
				p1++;
				for(int i=1;i<p1;++i)
					if(a[id(pp,i)]==a[id(pp,p1-1)])
					{
						ps=i;
						break;
					}
				work(p1,ps);
				if(check())
				{
					write(ps);putchar(' ');
					write(p1);puts("");
				}
				else puts("-1");
			}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					a[id(i,j)]=0;
		}
		else
		{
			int ps=-1;
			for(int i=p1+2;i<=m;++i)
				if(a[id(pp,i)]<a[id(pp,i-1)])
				{
					ps=i;
					break;
				}
			int flag=1;
			if(p1!=1&&a[id(pp,p1-1)]==a[id(pp,p1)]) flag=0;
			if(ps!=m&&a[id(pp,ps)]==a[id(pp,ps+1)]) flag=0;
			if(!flag)
				puts("-1");
			else
			{
				work(ps,p1);
				if(check())
				{
					write(p1);putchar(' ');
					write(ps);puts("");
				}
				else puts("-1");
			}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					a[id(i,j)]=0;
		}
	}
	return 0;
}