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

const int N=105;
int t,n,k,m,a[N],b[N],now[N],ok;

inline int query(int x)
{
	printf("%lld\n",x);
	fflush(stdout);
	int tmp=read();
	if(tmp==-1) exit(0);
	return tmp;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();m=0;ok=1;
		memset(now,0,sizeof(now));
		int nn=n;
		while(nn) a[++m]=nn%k,nn/=k;
		if(query(0)==1) continue;
		for(int i=1;i<=n-1&&ok;++i)
		{
			int tmp=i,l=0;
			while(tmp)
				b[++l]=tmp%k,tmp/=k;
			for(int j=1;j<=l;++j)
				b[j]=(b[j]-now[j]+k)%k;
			int sum=0;
			for(int j=1,p=1;j<=l;++j,p*=k)
				sum+=b[j]*p,now[j]=(now[j]+b[j])%k;
			ok&=(1^query(sum));
		}
	}
	return 0;
}