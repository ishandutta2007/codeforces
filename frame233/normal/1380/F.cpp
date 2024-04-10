// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
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
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
const int mod=998244353;
struct matrix{
	ll a,b,c,d;
	Finline matrix operator * (const matrix &o)const
	{
		return (matrix){(a*o.a+b*o.c)%mod,(a*o.b+b*o.d)%mod,(c*o.a+d*o.c)%mod,(c*o.b+d*o.d)%mod};
	}
}qwq[105];
int a[N];
int ls[N<<1],rs[N<<1],node_cnt;
matrix val[N<<1];
int build(int l,int r)
{
	int cur=++node_cnt;
	if(l==r)
	{
		val[cur]=qwq[a[l-1]*10+a[l]];
		return cur;
	}
	int mid=(l+r)>>1;
	ls[cur]=build(l,mid);
	rs[cur]=build(mid+1,r);
	val[cur]=val[ls[cur]]*val[rs[cur]];
	return cur;
}
void Update(int pos,int l,int r,int cur)
{
	if(l==r)
	{
		val[cur]=qwq[a[l-1]*10+a[l]];
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) Update(pos,l,mid,ls[cur]);
	else Update(pos,mid+1,r,rs[cur]);
	val[cur]=val[ls[cur]]*val[rs[cur]];
}
Finline int Query()
{
	return val[1].a;
}
int main()
{
	for(int i=0;i<100;++i)
	{
		qwq[i].a=(i%10)+1;
		qwq[i].b=1;
		if(i>=10) for(int j=0;j<10;++j) qwq[i].c+=(i-j<10);
		qwq[i].d=0;
	}
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) scanf("%1d",&a[i]);
	build(1,n);
	int x,y;
	while(m--)
	{
		read(x,y);
		a[x]=y;
		Update(x,1,n,1);
		if(x!=n) Update(x+1,1,n,1);
		printf("%d\n",Query());
	}
	return 0;
}