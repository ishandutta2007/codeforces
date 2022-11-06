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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
int t,n,a[N],b[N],pre[N],suc[N];

inline bool check(int x[],int y);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=b[n-i+1]=read();
		if(check(a,n)||check(b,n))
		{
			printf("YES\n");
			continue;
		}
		suc[n+1]=0;
		for(int i=1;i<=n;++i)
			if(a[i]<pre[i-1]||pre[i-1]==-1) pre[i]=-1;
			else pre[i]=a[i]-pre[i-1];
		for(int i=n;i>=1;--i)
			if(a[i]<suc[i+1]||suc[i+1]==-1) suc[i]=-1;
			else suc[i]=a[i]-suc[i+1];
		int flag=0;
		for(int i=1;i<=n-1;++i)
		{
			if(pre[i-1]==-1||suc[i+2]==-1) continue;
			b[1]=pre[i-1];b[2]=a[i];b[3]=a[i+1];b[4]=suc[i+2];
			if(check(b,4)){printf("YES\n");flag=1;break;}
			b[1]=pre[i-1];b[2]=a[i+1];b[3]=a[i];b[4]=suc[i+2];
			if(check(b,4)){printf("YES\n");flag=1;break;}
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}

inline bool check(int x[],int y)
{
	int now=x[1];
	for(int i=2;i<=y;++i)
		if(x[i]<now) return 0;
		else now=x[i]-now;
	return now==0;
}