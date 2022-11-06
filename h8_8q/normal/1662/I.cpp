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

const int N=2e5+5;
int t,n,m,a[N],b[N],c[N],lf[N],rf[N],len[N],ans;

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),b[i]=(i-1)*100;
	for(int i=1;i<=m;++i)
		c[i]=read();
	sort(c+1,c+1+m);
	for(int i=1,j=0;i<=n;++i)
	{
		a[i]+=a[i-1];
		while(j+1<=m&&c[j+1]<=b[i]) ++j;
		if(j&&c[j]<=b[i]) lf[i]=c[j];else lf[i]=-1;
	}
	for(int i=n,j=m+1;i>=1;--i)
	{
		while(j-1>=1&&c[j-1]>=b[i]) --j;
		if(j!=m+1&&c[j]>=b[i]) rf[i]=c[j];else rf[i]=-1;
	}
	for(int i=1;i<=n;++i)
	{
		len[i]=1e18;
		if(lf[i]!=-1) len[i]=min(len[i],b[i]-lf[i]);
		if(rf[i]!=-1) len[i]=min(len[i],rf[i]-b[i]);
	}
	for(int i=1,j=1;i<=n;++i)
	{
		int ps=-1;
		if(lf[i]!=-1) ps=max(ps,lf[i]);
		if(rf[i]!=-1) ps=max(ps,b[i]*2-rf[i]);
		while(j<=i&&lf[i]!=-1&&ps!=-1&&ps>=b[j]+len[j]) ++j;
		ans=max(ans,a[i]-a[j-1]);
	}
	write(ans);
	return 0;
}