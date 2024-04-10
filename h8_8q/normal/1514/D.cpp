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

const int N=3e5+5;
int n,q,m,a[N],b[N],d[N],ans[N],now,len,L,R;

struct Qus
{
	int l,r,id;
	bool operator < (const Qus &x)const
	{
		if(l/m==x.l/m) return r<x.r;
		return l<x.l;
	}
}c[N];

void add(int x)
{
    --d[b[a[x]]];++b[a[x]];
    now=max(now,b[a[x]]);
    ++d[b[a[x]]];
}

void del(int x)
{
    --d[b[a[x]]];
    if(now==b[a[x]]&&!d[b[a[x]]]) --now;
    --b[a[x]];++d[b[a[x]]];
}

signed main()
{
	n=read();q=read();
	m=sqrt(n);
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read();
		c[i]=(Qus){l,r,i};
	}
	sort(c+1,c+1+q);
	L=1,R=0;
	for(int i=1;i<=q;++i)
	{
		int l=c[i].l,r=c[i].r;
		while(L>l) add(--L);
		while(R<r) add(++R);
		while(R>r) del(R--);
		while(L<l) del(L++);
		//auto tmp=s.end();tmp--;
		if(2*now<=r-l+1) ans[c[i].id]=1;
		else ans[c[i].id]=2*now-(r-l+1);
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}