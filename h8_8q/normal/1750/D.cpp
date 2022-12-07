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
#define SZ(x) ((int)(x.size()))
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

const int N=1e6+5,mod=998244353;
int t,n,m,a[N],k,b[N],c[N],d[N],w[5000],cnt[5000],pw[5000];

signed main()
{
	t=read();
	for(int i=0;i<4000;++i)
		cnt[i]=__builtin_popcount(i);
	for(int i=0;i<=9;++i)
		pw[1<<i]=i;
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int tmp=a[1];k=0;
		for(int i=2;i*i<=tmp;++i)
			if(tmp%i==0)
			{
				b[++k]=i;
				while(tmp%i==0)
					tmp/=i,c[k]++;
			}
		if(tmp!=1) b[++k]=tmp,c[k]=1;
		int ans=1;
		for(int i=2;i<=n;++i)
		{
			if(a[i-1]%a[i]!=0)
			{
				ans=0;
				break;
			}
			int tmp=a[i-1]/a[i],tot=0,lol=1;
			for(int j=1;j<=k;++j)
				if(tmp%b[j]==0)
				{
					while(tmp%b[j]==0)
						tmp/=b[j];
					d[tot++]=b[j];
				}
			int tmp2=a[i];
			for(int j=1;j<=k;++j)
				if(tmp2%b[j]==0)
					while(tmp2%b[j]==0)
						tmp2/=b[j],lol*=b[j];
			int res=m/lol;w[0]=lol;
			for(int j=1;j<(1<<tot);++j)
			{
				w[j]=w[j-lowbit(j)]*d[pw[lowbit(j)]];
				if(cnt[j]&1) res=(res-m/w[j]+mod)%mod;
				else res=(res+m/w[j])%mod;
			}
			ans=ans*res%mod;
		}
		write(ans);puts("");
		for(int i=1;i<=k;++i)
			b[i]=c[i]=0;
	}
	return 0;
}