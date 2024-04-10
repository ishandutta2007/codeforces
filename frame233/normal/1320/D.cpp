// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
const int mod1=998244353;
const int mod2=1000000007;
const int mod3=1000000009;
const int base=19260817;
int cnt[N];
ll f1[N],f2[N],f3[N],pw1[N],pw2[N],pw3[N];
int a[N],b[N];
void init(int n)
{
	pw1[0]=pw2[0]=pw3[0]=1;
	for(int i=1;i<=n+1;++i)
	{
		pw1[i]=pw1[i-1]*base%mod1;
		pw2[i]=pw2[i-1]*base%mod2;
		pw3[i]=pw3[i-1]*base%mod3;
		f1[i]=(f1[i-1]*base+b[i])%mod1;
		f2[i]=(f2[i-1]*base+b[i])%mod2;
		f3[i]=(f3[i-1]*base+b[i])%mod3;
	}
}
bool used[N];
int t[N],pos;
int to[N];
int nxt[N],lst[N];
ll calc(ll *f1,ll mod1,ll *pw1,int x,int len)
{
	int L=std::lower_bound(t+1,t+pos+1,x)-t,R=std::upper_bound(t+1,t+pos+1,x+len-1)-t-1;
	ll val1=(f1[R]-f1[L-1]*pw1[R-L+1]%mod1+mod1)%mod1;
	if(to[x]==x-1)
	{
		int nd=min(x+len-1,nxt[x]);
		int tmp=std::lower_bound(t+1,t+pos+1,nd)-t;
		if(t[tmp]==nd)
		{
			val1=((f1[tmp-1]-f1[L-1]*pw1[tmp-L]%mod1+mod1)%mod1*pw1[R-tmp]+(f1[R]-f1[tmp]*pw1[R-tmp]%mod1+mod1)%mod1)%mod1;
		}
		else
		{
			val1=(((f1[tmp-1]-f1[L-1]*pw1[tmp-L]%mod1+mod1)%mod1*base%mod1+1)*pw1[R-tmp+1]%mod1+(f1[R]-f1[tmp-1]*pw1[R-tmp+1]%mod1+mod1)%mod1)%mod1;
		}
	}
	if(to[x+len-1]==x+len)
	{
		val1=(val1*base+1)%mod1;
	}
	return val1;
}
Finline bool check1(int x,int y,int len)
{
	return calc(f1,mod1,pw1,x,len)==calc(f1,mod1,pw1,y,len);
}
Finline bool check2(int x,int y,int len)
{
	return calc(f2,mod2,pw2,x,len)==calc(f2,mod2,pw2,y,len);
}
Finline bool check3(int x,int y,int len)
{
	return calc(f3,mod3,pw3,x,len)==calc(f3,mod3,pw3,y,len);
}
int main()
{
	memset(to,255,sizeof(to));
	int n;
	read(n);
	for(int i=1;i<=n;++i) scanf("%1d",&a[i]),cnt[i]=cnt[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		if(a[i])
		{
			int j=i;
			while(j<n&&a[j+1]) ++j;
			for(int k=i;k<=j;++k) nxt[k]=j,lst[k]=i;
			i=j;
		}
	}
	for(int i=1;i<n;++i)
	{
		if(a[i]==1&&a[i+1]==1)
		{
			used[i]=used[i+1]=1;
			to[i]=i+1;
			to[i+1]=i;
			++i;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			t[++pos]=i;
			b[pos]=a[i];
		}
	}
	init(pos);
	int _;
	read(_);
	int x,y,len;
	while(_--)
	{
		read(x,y,len);
		if(cnt[x+len-1]-cnt[x-1]==cnt[y+len-1]-cnt[y-1]&&(cnt[x+len-1]-cnt[x-1]==len||check1(x,y,len)&&check2(x,y,len)&&check3(x,y,len)))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}