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

const int NN=1e6+5,N=4e5+5,M=20,mod=1e9+7;
int n,m,s[NN],c[N],f1[N],f2[N],f5[N],fib[N];

int AND[2][2]={{1,1},{0,1}},IAND[2][2]={{1,mod-1},{0,1}};
int OR[2][2]={{1,0},{1,1}},IOR[2][2]={{1,0},{mod-1,1}};
int XOR[2][2]={{1,1},{1,mod-1}},IXOR[2][2]={{500000004,500000004},{500000004,mod-500000004}};

struct Poly
{
	int a[M];
	void operator += (const Poly &b)
	{
		for(int i=0;i<=17;++i)
			a[i]=(a[i]+b.a[i])%mod;
	}
	void operator -= (const Poly &b)
	{
		for(int i=0;i<=17;++i)
			a[i]=(a[i]-b.a[i]+mod)%mod;
	}
	Poly operator * (const Poly &b)const
	{
		Poly res;
		clr(res.a,18);
		for(int i=0;i<=17;++i)
			for(int j=0;i+j<=17;++j)
				res.a[i+j]=(res.a[i+j]+a[i]*b.a[j]%mod)%mod;
		return res;
	}
}f3[N],f4[N];

inline int q_pow(int a,int b);
inline void DWT(Poly *a,int n);
inline void IDWT(Poly *a,int n);
inline void failed_system_test(Poly *a,Poly *b,int n);
inline int init(int n);
inline void mul(int *a,int *b,int c[2][2],int ic[2][2],int n);
inline void fast_will_tle(int *a,int c[2][2],int n);

signed main()
{
	n=read();fib[1]=1;
	for(int i=1;i<=n;++i)
		s[i]=read(),m=max(m,s[i]);
	m=init(m);
	for(int i=1;i<m;++i)
	{
		c[i]=c[i>>1]+(i&1);
		if(i!=1) fib[i]=(fib[i-1]+fib[i-2])%mod;
	}
	for(int i=1;i<=n;++i)
	{
		f1[s[i]]++,f2[s[i]]++;
		f3[s[i]].a[c[s[i]]]++;
		f4[s[i]].a[c[s[i]]]++;
	}
	failed_system_test(f3,f4,m);
	for(int i=0;i<m;++i)
		f5[i]=f3[i].a[c[i]]*fib[i];
	mul(f1,f2,XOR,IXOR,m);
	for(int i=0;i<m;++i)
		f1[i]=f1[i]*fib[i];
	clr(f2,m);
	for(int i=1;i<=n;++i)
		f2[s[i]]++;
	for(int i=0;i<m;++i)
		f2[i]=f2[i]*fib[i];
	mul(f1,f2,AND,IAND,m);
	mul(f1,f5,AND,IAND,m);
	int ans=0;
	for(int i=1;i<m;i<<=1)
		ans=(ans+f1[i])%mod;
	printf("%lld\n",ans);
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

inline void DWT(Poly *a,int n)
{
	for(int l=2;l<=n;l<<=1)
	{
		int len=l>>1;
		for(int i=0;i<n;i+=l)
			for(int k=0;k<len;++k)
				a[len|i|k]+=a[i|k];
	}
}

inline void IDWT(Poly *a,int n)
{
	for(int l=2;l<=n;l<<=1)
	{
		int len=l>>1;
		for(int i=0;i<n;i+=l)
			for(int k=0;k<len;++k)
				a[len|i|k]-=a[i|k];
	}
}

inline void failed_system_test(Poly *a,Poly *b,int n)
{
	DWT(a,n);
	DWT(b,n);
	for(int i=0;i<n;++i)
		a[i]=a[i]*b[i];
	IDWT(a,n);
	
}

inline int init(int n)
{
	int res=1;
	for(;res<=n;res<<=1);
	return res;
}

inline void mul(int *a,int *b,int c[2][2],int ic[2][2],int n)
{
	fast_will_tle(a,c,n);
	fast_will_tle(b,c,n);
	for(int i=0;i<n;++i)
		a[i]=a[i]*b[i]%mod;
	fast_will_tle(a,ic,n);
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