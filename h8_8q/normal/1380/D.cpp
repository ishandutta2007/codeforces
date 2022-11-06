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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2e5+5;
int n,m,p,x,y,k,a[N],b[N];

struct Node
{
	int l,r,v;
}c[N];

signed main()
{
	n=read();m=read();x=read();k=read();y=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	int now=1,last=1,mx=0;
	for(int i=1;i<=n;++i)
		if(now<=m&&a[i]==b[now])
		{
			if(last<=i-1) c[++p]=(Node){last,i-1,mx};
			last=i+1;now++;mx=a[i+1];
		}
		else mx=max(mx,a[i]);
	if(last<=n) c[++p]=(Node){last,n,mx};
	int ans=0;
	for(int i=1;i<=p;++i)
	{
		if(c[i].r-c[i].l+1<k)
		{
			if(c[i].v>a[c[i].l-1]&&c[i].v>a[c[i].r+1])
			{
				printf("-1\n");
				return 0;
			}
			ans+=y*(c[i].r-c[i].l+1);
		}
		else
		{
			if(y*k<x)
			{
				if(c[i].v>a[c[i].l-1]&&c[i].v>a[c[i].r+1])
					ans+=x+y*(c[i].r-c[i].l+1-k);
				else ans+=y*(c[i].r-c[i].l+1);
			}
			else
				ans+=x*(((c[i].r-c[i].l+1))/k)+y*(((c[i].r-c[i].l+1))%k);
		}
	}
	if(now==m+1) printf("%lld\n",ans);
	else printf("%d\n",-1);
	return 0;
}