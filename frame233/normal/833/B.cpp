// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG f_rintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mk_r std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=35005;
int f[N],g[N],a[N];
int vis[N];
int _l,_r,cnt;
Finline void inc_l()
{
	cnt-=(--vis[a[_l++]])==0;
}
Finline void dec_l()
{
	cnt+=(++vis[a[--_l]])==1;
}
Finline void inc_r()
{
	cnt+=(++vis[a[++_r]])==1;
}
Finline void dec_r()
{
	cnt-=(--vis[a[_r--]])==0;
}
void solve(int l,int r,int L,int R)
{
	if(l>r) return;
	int mid=(l+r)>>1;
	int maxx=-inf,pos=0;
	for(int i=L;i<=R&&i<mid;++i)
	{
		while(_l>i+1) dec_l();
		while(_r<mid) inc_r();
		while(_l<i+1) inc_l();
		while(_r>mid) dec_r();
		int tmp=cnt+g[i];
		if(tmp>maxx) maxx=tmp,pos=i;
	}
	f[mid]=maxx;
	solve(l,mid-1,L,pos),solve(mid+1,r,pos,R);
}
int main()
{
	int n,k;read(n,k);
	for(int i=1;i<=n;++i) read(a[i]);
	memset(g,-63,sizeof(g));
	g[0]=0;
	_l=1,_r=0;
	for(int i=1;i<=k;++i)
	{
		solve(1,n,0,n);
		memcpy(g,f,sizeof(f));
	}
	printf("%d\n",f[n]);
	return 0;
}