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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
char ibuf[1<<21],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
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
char obuf[1<<24],buf[21],*T=obuf,*Q=buf;
template <typename _Tp>Finline void print(_Tp u,char ch='\n')
{
	if(!u) *T++=48;
	else
	{
		if(u<0) u=-u,*T++='-';
		while(u) *Q++=u%10+48,u/=10;
		while(Q!=buf) *T++=*--Q;
	}
	*T++=ch;
}

const int N=100005;
const int mod=1000000007;
template <typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template <typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int qwq,qaq;
ll ksm(ll a,int b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res*res%mod;
}
struct seg_tr{
	struct Node{
		int ls,rs;
		int sum1,sum2;
		int tag1,tag2,tag3;
		Finline Node():ls(0),rs(0),sum1(0),sum2(0),tag1(1),tag2(0),tag3(0){}
	}f[N<<6];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].sum1=f[f[x].ls].sum1;
		add(f[x].sum1,f[f[x].rs].sum1);
		f[x].sum2=f[f[x].ls].sum2;
		add(f[x].sum2,f[f[x].rs].sum2);
	}
	Finline void mul(int cur,int val)
	{
		if(!cur) return;
		f[cur].sum1=1ll*f[cur].sum1*val%mod;
		f[cur].sum2=1ll*f[cur].sum2*val%mod;
		f[cur].tag1=1ll*f[cur].tag1*val%mod;
		f[cur].tag2=1ll*f[cur].tag2*val%mod;
		f[cur].tag3=1ll*f[cur].tag3*val%mod;
	}
	Finline void Add2(int &cur,int l,int r,int val)
	{
		if(!cur) cur=++node_cnt;
		add(f[cur].sum1,1ll*(r-l+1)*val%mod);
		add(f[cur].tag2,val);
	}
	Finline void Add3(int &cur,int l,int r,int val)
	{
		if(!cur) cur=++node_cnt;
		add(f[cur].sum2,1ll*(r-l+1)*val%mod);
		add(f[cur].tag3,val);
	}
	Finline void PushDown(int cur,int l,int r)
	{
		if(f[cur].tag1>1)
		{
			mul(f[cur].ls,f[cur].tag1);
			mul(f[cur].rs,f[cur].tag1);
			f[cur].tag1=1;
		}
		if(f[cur].tag2)
		{
			int mid=(l+r)>>1;
			Add2(f[cur].ls,l,mid,f[cur].tag2);
			Add2(f[cur].rs,mid+1,r,f[cur].tag2);
			f[cur].tag2=0;
		}
		if(f[cur].tag3)
		{
			int mid=(l+r)>>1;
			Add3(f[cur].ls,l,mid,f[cur].tag3);
			Add3(f[cur].rs,mid+1,r,f[cur].tag3);
			f[cur].tag3=0;
		}
	}
	void Update(int &cur,int L,int R,int l,int r,int val)
	{
		if(!cur) cur=++node_cnt;
		if(L<=l&&r<=R)
		{
			Add2(cur,l,r,1);
			Add3(cur,l,r,val);
			return;
		}
		PushDown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update(f[cur].ls,L,R,l,mid,val);
		if(R>mid) Update(f[cur].rs,L,R,mid+1,r,val);
		PushUp(cur);
	}
	Finline void Modify(int cur,int val)
	{
		mul(cur,val);
	}
	int merge(int a,int b,int l,int r)
	{
		if(!a||!b) return a|b;
		if(l==r)
		{
			add(qwq,1ll*f[a].sum1*f[b].sum1%mod);
			add(qaq,1ll*f[a].sum1*f[b].sum2%mod);
			add(qaq,1ll*f[a].sum2*f[b].sum1%mod);
			add(f[a].sum1,f[b].sum1);
			add(f[a].sum2,f[b].sum2);
			return a;
		}
		if(!f[a].ls&&!f[a].rs&&!f[b].ls&&!f[b].rs)
		{
			add(qwq,1ll*f[a].tag2*f[b].tag2%mod*(r-l+1)%mod);
			add(qaq,1ll*f[a].tag2*f[b].tag3%mod*(r-l+1)%mod);
			add(qaq,1ll*f[a].tag3*f[b].tag2%mod*(r-l+1)%mod);
			Add2(a,l,r,f[b].tag2);
			Add3(a,l,r,f[b].tag3);
			return a;
		}
		if(!f[a].ls&&!f[a].rs)
		{
			add(qwq,1ll*f[a].tag2*f[b].sum1%mod);
			add(qaq,1ll*f[a].tag2*f[b].sum2%mod);
			add(qaq,1ll*f[a].tag3*f[b].sum1%mod);
			Add2(b,l,r,f[a].tag2);
			Add3(b,l,r,f[a].tag3);
			return b;
		}
		if(!f[b].ls&&!f[b].rs)
		{
			add(qwq,1ll*f[a].sum1*f[b].tag2%mod);
			add(qaq,1ll*f[a].sum1*f[b].tag3%mod);
			add(qaq,1ll*f[a].sum2*f[b].tag2%mod);
			Add2(a,l,r,f[b].tag2);
			Add3(a,l,r,f[b].tag3);
			return a;
		}
		PushDown(a,l,r);
		PushDown(b,l,r);
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		PushUp(a);
		return a;
	}
}tr;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add_edge(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int l[N],r[N];
int root[N];
int dep[N];
int ans,dp[N];
int mul;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	dp[x]=r[x]-l[x]+1;
	tr.Update(root[x],l[x],r[x],1,100000,dep[x]);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
			qwq=0,qaq=0;
			tr.Modify(root[x],dp[c[i].v]);
			tr.Modify(root[c[i].v],dp[x]);
			dp[x]=1ll*dp[x]*dp[c[i].v]%mod;
			ll inv=ksm(dp[x]);
			root[x]=tr.merge(root[x],root[c[i].v],1,100000);
			sub(ans,2ll*dep[x]*qwq%mod*inv%mod);
			add(ans,inv*qaq%mod);
		}
	}
}
int main()
{
	int n;
	read(n);
	mul=1;
	for(int i=1;i<=n;++i)
	{
		read(l[i],r[i]);
		mul=1ll*mul*(r[i]-l[i]+1)%mod;
	}
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add_edge(x,y),add_edge(y,x);
	}
	dep[0]=-1;
	dfs(1,0);
	printf("%lld\n",1ll*mul*ans%mod);
	return fwrite(obuf,1,T-obuf,stdout),0;
}
// I AK IOI