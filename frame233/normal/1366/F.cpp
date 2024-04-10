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
const ll INF=0x7fffffffffffffff;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=2005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int dis[N][N];
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
ll k[N];
ll b[N];
struct node{
	ll x,y;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y>o.y:x<o.x;
	}
}a[N];
int st[N],top;
Finline ll calc(int i,ll x)
{
	i=st[i];
	return -x*a[i].x+a[i].y;
}
int main()
{
	int n,m,q;
	read(n,m,q);
	int x,y;
	ll z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		addedge(x,y,z);
		addedge(y,x,z);
		chmax(k[x],z);
		chmax(k[y],z);
	}
	memset(dis,-63,sizeof(dis));
	dis[0][1]=0;
	for(int t=0;t<n;++t)
	{
		for(int i=1;i<=n;++i)
		{
			for(int _=front[i];_;_=c[_].nxt)
			{
				chmax(dis[t+1][c[_].v],dis[t][i]+c[_].w);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		b[i]=-1e18;
		for(int j=0;j<=n;++j)
		{
			if(dis[j][i]>=0)
			{
				chmax(b[i],dis[j][i]-k[i]*j);
			}
		}
		a[i]=(node){-k[i],b[i]};
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		if(a[i].x==a[i-1].x) continue;
		while(top>1&&(a[i].y-a[st[top]].y)*(a[st[top]].x-a[st[top-1]].x)>=(a[st[top]].y-a[st[top-1]].y)*(a[i].x-a[st[top]].x)) --top;
		st[++top]=i;
	}
	int ans=0;
	for(int i=1;i<=n&&i<=q;++i)
	{
		int tmp=0;
		for(int j=1;j<=n;++j) chmax(tmp,dis[i][j]);
		add(ans,tmp%mod);
	}
	if(q>n)
	{
		int last=n;
		for(int i=top;i>1;--i)
		{
			int l=last+1,r=q;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(calc(i,mid)>=calc(i-1,mid)) l=mid;
				else r=mid-1;
			}
			if(calc(i,l)>=calc(i-1,l))
			{
				add(ans,calc(i,last+1)%mod*(l-last)%mod);
				add(ans,-1ll*a[st[i]].x*(((1ll*(l-last)*(l-last-1))>>1)%mod)%mod);
				last=l;
			}
		}
		if(last<q)
		{
			add(ans,calc(1,last+1)%mod*(q-last)%mod);
			add(ans,-1ll*a[st[1]].x*(((1ll*(q-last)*(q-last-1))>>1)%mod)%mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}