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

const int N=1e6+6;
int n,m,a[N],b[N],sx,sy,c[N],sm[N];

bool check(int x)
{
	int mx=0,fl=0;
	for(int i=1,j=m;i<=n;++i)
	{
		while(j&&a[i]+b[j]>x) --j;
		c[i]=j;sm[i]=sm[i-1]+j;
	}
	for(int i=m,j=0,ps=n;i>=1;--i)
	{
		while(ps&&c[ps]<m-i) ps--;
		int tmp=sm[ps]-(m-i)*ps-i*(n-j)+(sm[n]-sm[j]);
		if(mx<tmp) mx=tmp,fl=0;
		if(mx==tmp) fl|=(sy<=i||sx<=ps);
		while(j<n&&c[j+1]==i) ++j;
	}
	return fl;
}

signed main()
{
	n=read();m=read();
	sx=sy=1;
	for(int i=1;i<=n;++i)
		a[i]=read(),sx+=(a[i]<a[1]);
	for(int i=1;i<=m;++i)
		b[i]=read(),sy+=(b[i]<b[1]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int l=0,r=a[sx]+b[sy],ps=r;
	while(l<=r)
	{
		if(check(mid))
			ps=mid,r=mid-1;
		else l=mid+1;
	}
	write(ps);
	return 0;
}