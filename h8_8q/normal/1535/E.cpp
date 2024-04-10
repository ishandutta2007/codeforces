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

const int N=3e5+5;
int q,a[N],c[N],dp[N][21],dep[N]; 

signed main()
{
	q=read();
	a[1]=read();c[1]=read();
	for(int p=2;p<=q+1;++p)
	{
		int opt=read();
		if(opt==1)
		{
			int fa=read()+1,x=read(),y=read();
			a[p]=x;c[p]=y;dp[p][0]=fa;dep[p]=dep[fa]+1;
			for(int i=1;i<=20;++i)
				dp[p][i]=dp[dp[p][i-1]][i-1];
		}
		else
		{
			int x=read()+1,qwq=x;
			int y=read();
			int a1=0,a2=0;
			while(a[qwq])
			{
				x=qwq;
				for(int i=20;i>=0;--i)
					if(a[dp[x][i]])
						x=dp[x][i];
				if(a2+a[x]<=y)
				{
					a1+=a[x]*c[x];
					a2+=a[x];
					a[x]=0;
				}
				else
				{
					a1+=(y-a2)*c[x];
					a[x]-=y-a2;a2=y;
					break;
				}
			}
			printf("%lld %lld\n",a2,a1);
			fflush(stdout);
		}
	}
	return 0;
}