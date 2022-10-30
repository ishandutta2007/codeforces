// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
int a[N],Log2[N],n;
int f[N][21],g[N][21];
Finline pi qry(int l,int r)
{
	int k=Log2[r-l+1];
	return mkpr(min(g[l][k],g[r-(1<<k)+1][k]),max(f[l][k],f[r-(1<<k)+1][k]));
}
int ans[N];
int main()
{
	for(int i=2;i<N;++i) Log2[i]=Log2[i>>1]+1;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	a[0]=a[1],a[n+1]=a[n];
	for(int i=n;i>=0;--i)
	{
		f[i][0]=min(a[i],a[i+1]),g[i][0]=max(a[i],a[i+1]);
		for(int j=1;j<=20&&i+(1<<(j-1))<=n;++j) f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	}
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[i-1]||a[i]==a[i+1])
		{
			ans[i]=a[i];
			continue;
		}
		int l=1,r=min(i,n-i+1);
		while(l<r)
		{
			int mid=(l+r)>>1;
			pi tmp=qry(i-mid,i+mid-1);
			if(tmp.first<=tmp.second) r=mid;
			else l=mid+1;
		}
		chmax(res,r-1);
		pi tmp=qry(i-r,i+r-1);
		if((r&1)==(a[i]>a[i-1])) ans[i]=tmp.first;
		else ans[i]=tmp.second;
	}
	printf("%d\n",res);
	for(int i=1;i<=n;++i) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}