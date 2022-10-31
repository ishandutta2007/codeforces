// Author -- Frame

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

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
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

const int N=100005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
Finline ll calc(ll x)
{
	return x*(x+1)>>1;
}
struct node{
	ll a,b,c;
};
node operator + (node a,const node &b)
{
	add(a.a,b.a),add(a.b,b.b),add(a.c,b.c);
	return a;
}
int n;
struct seg_tr{
	struct Node{
		int ls,rs;
		ll F,G,FG,Fi;
		int maxF,minG;
		int tag1,tag2;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].F=f[f[x].ls].F,add(f[x].F,f[f[x].rs].F);
		f[x].G=f[f[x].ls].G,add(f[x].G,f[f[x].rs].G);
		f[x].FG=f[f[x].ls].FG,add(f[x].FG,f[f[x].rs].FG);
		f[x].Fi=f[f[x].ls].Fi,add(f[x].Fi,f[f[x].rs].Fi);
		f[x].maxF=max(f[f[x].ls].maxF,f[f[x].rs].maxF);
		f[x].minG=min(f[f[x].ls].minG,f[f[x].rs].minG);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].tag1=f[cur].tag2=-1;
		if(l==r)
		{
			f[cur].maxF=f[cur].F=1,f[cur].minG=f[cur].G=n,f[cur].FG=n,f[cur].Fi=l;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		pushup(cur);
		return cur;
	}
	Finline void upd1(int x,int l,int r,int val)
	{
		f[x].F=1ll*(r-l+1)*val%mod;
		f[x].FG=1ll*f[x].G*val%mod;
		f[x].Fi=1ll*(calc(r)-calc(l-1))%mod*val%mod;
		f[x].maxF=val,f[x].tag1=val;
	}
	Finline void upd2(int x,int l,int r,int val)
	{
		f[x].G=1ll*(r-l+1)*val%mod;
		f[x].FG=1ll*f[x].F*val%mod;
		f[x].minG=val,f[x].tag2=val;
	}
	Finline void pushdown(int cur,int l,int r)
	{
		int mid=(l+r)>>1;
		if(~f[cur].tag1)
		{
			upd1(f[cur].ls,l,mid,f[cur].tag1);
			upd1(f[cur].rs,mid+1,r,f[cur].tag1);
			f[cur].tag1=-1;
		}
		if(~f[cur].tag2)
		{
			upd2(f[cur].ls,l,mid,f[cur].tag2);
			upd2(f[cur].rs,mid+1,r,f[cur].tag2);
			f[cur].tag2=-1;
		}
	}
	void Update1(int L,int R,int l,int r,int cur,int val)
	{
		if(L<=l&&r<=R)
		{
			upd1(cur,l,r,val);
			return;
		}
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update1(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update1(L,R,mid+1,r,f[cur].rs,val);
		pushup(cur);
	}
	void Update2(int L,int R,int l,int r,int cur,int val)
	{
		if(L<=l&&r<=R)
		{
			upd2(cur,l,r,val);
			return;
		}
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update2(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update2(L,R,mid+1,r,f[cur].rs,val);
		pushup(cur);
	}
	node Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return (node){f[cur].G,f[cur].FG,f[cur].Fi};
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return Query(L,R,l,mid,f[cur].ls)+Query(L,R,mid+1,r,f[cur].rs);
		if(L<=mid) return Query(L,R,l,mid,f[cur].ls);
		return Query(L,R,mid+1,r,f[cur].rs);
	}
	int find1(int L,int R,int l,int r,int cur,int val)
	{
		if(l==r) return f[cur].maxF>=val?l:n+1;
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=l&&r<=R)
		{
			if(f[f[cur].ls].maxF>=val) return find1(L,R,l,mid,f[cur].ls,val);
			return find1(L,R,mid+1,r,f[cur].rs,val);
		}
		if(L<=mid&&R>mid) return min(find1(L,R,l,mid,f[cur].ls,val),find1(L,R,mid+1,r,f[cur].rs,val));
		if(L<=mid) return find1(L,R,l,mid,f[cur].ls,val);
		return find1(L,R,mid+1,r,f[cur].rs,val);
	}
	int find2(int L,int R,int l,int r,int cur,int val)
	{
		if(l==r) return f[cur].minG<=val?l:n+1;
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=l&&r<=R)
		{
			if(f[f[cur].ls].minG<=val) return find2(L,R,l,mid,f[cur].ls,val);
			return find2(L,R,mid+1,r,f[cur].rs,val);
		}
		if(L<=mid&&R>mid) return min(find2(L,R,l,mid,f[cur].ls,val),find2(L,R,mid+1,r,f[cur].rs,val));
		if(L<=mid) return find2(L,R,l,mid,f[cur].ls,val);
		return find2(L,R,mid+1,r,f[cur].rs,val);
	}
}tr;
int a[N];
int pre[N],suf[N];
std::map<int,int> mp;
int f[N][21],g[N][21],Log2[N];
Finline pi Query(int L,int R)
{
	int k=Log2[R-L+1];
	return mkpr(max(f[L][k],f[R-(1<<k)+1][k]),min(g[L][k],g[R-(1<<k)+1][k]));
}
int main()
{
	for(int i=2;i<N;++i) Log2[i]=Log2[i>>1]+1;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i)
	{
		if(mp.find(a[i])==mp.end()) pre[i]=1;
		else pre[i]=mp[a[i]]+1;
		mp[a[i]]=i;
	}
	mp.clear();
	for(int i=n;i>=1;--i)
	{
		if(mp.find(a[i])==mp.end()) suf[i]=n;
		else suf[i]=mp[a[i]]-1;
		mp[a[i]]=i;
		f[i][0]=pre[i],g[i][0]=suf[i];
		for(int j=1;j<=20&&i+(1<<(j-1))<=n;++j) f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	}
	tr.build(1,n);
	ll ans=0;
	for(int i=n;i>=1;--i)
	{
		int p1=tr.find1(i,n,1,n,1,pre[i]);
		if(i<p1) tr.Update1(i,p1-1,1,n,1,pre[i]);
		int p2=tr.find2(i,n,1,n,1,suf[i]);
		if(i<p2) tr.Update2(i,p2-1,1,n,1,suf[i]);
		auto check=[&](int mid)->bool
		{
			pi tmp=Query(i,mid);
			return (i>tmp.first&&mid<tmp.second);
		};
		int l=i,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		if(check(l))
		{
			node tmp=tr.Query(i,l,1,n,1);
			ans+=1ll*i*(tmp.a-(calc(l)-calc(i-1))%mod)%mod-tmp.b+tmp.c;
		}
	}
	ans%=mod,ans+=mod,ans%=mod;
	printf("%lld\n",ans);
	return 0;
}