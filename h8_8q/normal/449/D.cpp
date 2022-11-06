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

const int N=4e6+5,mod=1e9+7;
int n,m,a[N],f[N];

int AND[2][2]={{1,1},{0,1}},IAND[2][2]={{1,mod-1},{0,1}};
int OR[2][2]={{1,0},{1,1}},IOR[2][2]={{1,0},{mod-1,1}};

inline int q_pow(int a,int b);
inline int init(int n);
inline void mul(int *a,int *b,int c[2][2],int ic[2][2],int n);
inline void fast_will_tle(int *a,int c[2][2],int n);

signed main()
{
	n=read();
	for(int i=0;i<n;++i)
	{
		a[i]=read();
		m=max(m,a[i]);
		f[a[i]]++;
	}
	m=init(m);
	fast_will_tle(f,AND,m);
	for(int i=0;i<m;++i)
		f[i]=q_pow(2,f[i]);
	fast_will_tle(f,IAND,m);
	if(f[0]==q_pow(2,n)) f[0]=(f[0]-1+mod)%mod;
	printf("%lld\n",f[0]);
	return 0;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline int init(int n)
{
	int res=1;
	for(;res<=n;res<<=1);
	return res;
}

inline void fast_will_tle(int *a,int c[2][2],int n)
{
	for(int l=2;l<=n;l<<=1)
	{
		int len=l>>1;
		for(int i=0;i<n;i+=l)
			for(int k=i;k<i+len;++k)
			{
				int tmp=a[k];
				a[k]=(c[0][0]*tmp+c[0][1]*a[k+len])%mod;
				a[k+len]=(c[1][0]*tmp+c[1][1]*a[k+len])%mod;
			}
	}
		
}