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

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5,BLOCK=200;
int n,m,num[N],now,pos[N];

struct Node
{
	int x,y;
}a[N];

struct BIT
{
	int lim,c[BLOCK+5];
	void add(int x,int v)
	{
		for(;x<=lim;x+=lowbit(x))
			c[x]+=v;
	}
	void update(int l,int r,int v)
	{
		add(l,v);add(r+1,-v);
	}
	int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
}sum[BLOCK+5];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i].x=read(),a[i].y=read();
	for(int i=2;i<=BLOCK;++i)
		sum[i].lim=i;
	for(int i=1;i<=m;++i)
	{
		int opt=read(),k=read();
		if(opt==1)
		{
			if(a[k].x+a[k].y<=BLOCK)
			{
				int l=(i-a[k].y)%(a[k].x+a[k].y);
				int r=(i-1)%(a[k].x+a[k].y);
				if(l<0)
				{
					l=(l+a[k].x+a[k].y)%(a[k].x+a[k].y);
					r=(r+a[k].x+a[k].y)%(a[k].x+a[k].y);
				}
				if(l>r)
				{
					sum[a[k].x+a[k].y].add(l+1,1);
					sum[a[k].x+a[k].y].update(1,r+1,1);
				}
				else sum[a[k].x+a[k].y].update(l+1,r+1,1);
			}
			else
			{
				for(int j=i+a[k].x;j<=m;j+=a[k].x+a[k].y)
				{
					num[j]++;
					if(j+a[k].y<=m)
						num[j+a[k].y]--;
				}
			}
			pos[k]=i;
		}
		else
		{
			if(a[k].x+a[k].y<=BLOCK)
			{
				int l=(pos[k]-a[k].y)%(a[k].x+a[k].y);
				int r=(pos[k]-1)%(a[k].x+a[k].y);
				if(l<0)
				{
					l=(l+a[k].x+a[k].y)%(a[k].x+a[k].y);
					r=(r+a[k].x+a[k].y)%(a[k].x+a[k].y);
				}
				if(l>r)
				{
					sum[a[k].x+a[k].y].add(l+1,-1);
					sum[a[k].x+a[k].y].update(1,r+1,-1);
				}
				else sum[a[k].x+a[k].y].update(l+1,r+1,-1);
			}
			else
			{
				for(int j=pos[k]+a[k].x;j<=m;j+=a[k].x+a[k].y)
				{
					num[j]--;
					if(j<i) now--; 
					if(j+a[k].y<=m)
					{
						num[j+a[k].y]++;
						if(j+a[k].y<i) now++;
					}
				}
			}
		}
		now+=num[i];
		int res=0;
		for(int j=2;j<=BLOCK;++j)
			res+=sum[j].query(i%j+1);
		write(now+res);puts("");
	}
	return 0;
}