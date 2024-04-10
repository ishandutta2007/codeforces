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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

int t,n,m;
int px[5],py[5];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		int x=read(),y=read();
		px[1]=1;py[1]=1;
		px[2]=n;py[2]=1;
		px[3]=1;py[3]=m;
		px[4]=n;py[4]=m;
		int p1,p2,mx=-1;
		for(int i=1;i<=4;++i)
			for(int j=i+1;j<=4;++j)
			{
				int tmp=abs(x-px[i])+abs(y-py[i])+abs(px[i]-px[j])+abs(py[i]-py[j])+abs(px[j]-x)+abs(py[j]-y);
				if(tmp>mx) mx=tmp,p1=i,p2=j;
			}
		printf("%lld %lld %lld %lld\n",px[p1],py[p1],px[p2],py[p2]);
	}
	return 0;
}