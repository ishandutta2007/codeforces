//by yjz
#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const int magic=10000;
const int proot=3;
const int mod=998244353;
ll kissme(ll x,int k)
{
	ll ans=1;
	for(;k>0;k>>=1)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
	}
	return ans;
}
int sz;
ll pw[300000];
void FFTinit(int n)
{
	sz=1;
	while(sz<n)sz<<=1;
	pw[0]=1;
	int tmp=kissme(proot,(mod-1)/sz);
	for(int i=1;i<=sz;i++)pw[i]=pw[i-1]*tmp%mod;
}
void FFT(ll a[],bool rev)
{
	for(int i=0,j=0;i<sz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int l=sz>>1;(j^=l)<l;l>>=1);
	}
	for(int k=1;k<sz;k<<=1)
	{
		int l=k+k;
		for(int i=0;i<sz;i+=l)
		{
			for(int j=0;j<k;j++)
			{
				int tmp=a[i+j+k]*pw[rev?sz-sz/l*j:sz/l*j]%mod;
				a[i+j+k]=a[i+j]-tmp<0?a[i+j]-tmp+mod:a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp>=mod?a[i+j]+tmp-mod:a[i+j]+tmp;
			}
		}
	}
	if(rev)
	{
		int tmp=kissme(sz,mod-2);
		for(int i=0;i<sz;i++)a[i]=1ll*a[i]*tmp%mod;
	}
}
ll a[300111],b[300111];
unsigned int A[200111],B[200111];
int n,m,q,cnt[1<<16],tab[22][200111];
char s[200111],t[200111];
void init()
{
	for(int i=1;i<(1<<16);i++)cnt[i]=cnt[i-(i&(-i))]+1;
	FFTinit(min(magic,n)+m);
	for(int i=0;i<m;i++)b[i]=t[i]=='1'?1:mod-1;
	FFT(b,0);
	for(int i=0;i<20&&i*magic+magic<=n;i++)
	{
		int tsz=min(magic,n-i*magic);
		memset(a,0,sizeof(a));
		for(int j=0;j<tsz;j++)
		{
			a[j]=s[i*magic+tsz-j-1]=='1'?1:mod-1;
		}
		FFT(a,0);
		for(int j=0;j<sz;j++)a[j]=a[j]*b[j]%mod;
		FFT(a,1);
		for(int j=0;j<=m-tsz;j++)tab[i][j]=((tsz-a[j+tsz-1]+mod)%mod)/2;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<32;j++)
		{
			if(s[i+j]=='1')A[i]|=1ll<<j;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<32;j++)
		{
			if(t[i+j]=='1')B[i]|=1ll<<j;
		}
	}
}
int count(unsigned int x){return cnt[x>>16]+cnt[x&65535];}
int query(int x,int y,int len)
{
	int ret=0;
	int tmp=min(len,(x/magic+1)*magic-x);
	len-=tmp;
	while(tmp>=32)ret+=count(A[x]^B[y]),x+=32,y+=32,tmp-=32;
	while(tmp--)ret+=s[x++]!=t[y++];
	while(len>=magic)ret+=tab[x/magic][y],x+=magic,y+=magic,len-=magic;
	while(len>=32)ret+=count(A[x]^B[y]),x+=32,y+=32,len-=32;
	while(len--)ret+=s[x++]!=t[y++];
	return ret;	
}
int main()
{
	scanf("%s",s);scanf("%s",t);
	n=strlen(s);m=strlen(t);
	init();
	cerr<<clock()<<endl;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int x,y,len;
		getiii(x,y,len);
		putsi(query(x,y,len));
	}
	return 0;
}