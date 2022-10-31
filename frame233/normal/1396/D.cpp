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

const int N=2015;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
struct node{
	int x,y,c;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
}a[N];
int t[N],val[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn,sum,tag;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
		f[x].sum=f[f[x].ls].sum;
		add(f[x].sum,f[f[x].rs].sum);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].tag=-1;
		f[cur].ls=f[cur].rs=0;
		if(l==r)
		{
			f[cur].minn=val[l];
			f[cur].sum=1ll*val[l]*(t[l+1]-t[l])%mod;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		pushup(cur);
		return cur;
	}
	Finline void upd(int cur,int l,int r,int val)
	{
		f[cur].minn=val;
		f[cur].sum=1ll*(t[r+1]-t[l])*val%mod;
		f[cur].tag=val;
	}
	Finline void pushdown(int cur,int l,int r)
	{
		if(~f[cur].tag)
		{
			int mid=(l+r)>>1;
			upd(f[cur].ls,l,mid,f[cur].tag);
			upd(f[cur].rs,mid+1,r,f[cur].tag);
			f[cur].tag=-1;
		}
	}
	void Update(int L,int R,int l,int r,int cur,int val)
	{
		if(L<=l&&r<=R) return upd(cur,l,r,val);
		int mid=(l+r)>>1;
		pushdown(cur,l,r);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,val);
		pushup(cur);
	}
	int find(int L,int R,int l,int r,int cur,int val)
	{
		if(l==r) return f[cur].minn<val?l:0;
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=l&&r<=R)
		{
			if(f[f[cur].rs].minn<val) return find(L,R,mid+1,r,f[cur].rs,val);
			return find(L,R,l,mid,f[cur].ls,val);
		}
		if(L<=mid&&R>mid) return max(find(L,R,l,mid,f[cur].ls,val),find(L,R,mid+1,r,f[cur].rs,val));
		if(L<=mid) return find(L,R,l,mid,f[cur].ls,val);
		return find(L,R,mid+1,r,f[cur].rs,val);
	}
	Finline int Query(){return f[1].sum;}
}tr;
node qwq[N];
int last[N];
std::multiset<int> S,rest[N];
int main()
{
	int n,k,L;read(n,k,L);
	for(int i=1;i<=n;++i) read(a[i].x,a[i].y,a[i].c);
	std::sort(a+1,a+n+1);
	int ans=0;
	a[n+1].x=L,a[0].x=-1;
	for(int i=1;i<=n;++i)
	{
		if(a[i].x==a[i-1].x) continue;
		int pos=0;
		t[++pos]=0,t[++pos]=L;
		int _=0;
		for(int j=i;j<=n;++j) t[++pos]=a[j].y,qwq[++_]=a[j];
		std::sort(qwq+1,qwq+_+1,[&](const node &a,const node &b)->bool{
			return a.y==b.y?a.x<b.x:a.y<b.y;
		});
		std::sort(t+1,t+pos+1);
		pos=std::unique(t+1,t+pos+1)-t-1;
		int p=0;
		S.clear();
		for(int j=1;j<=k;++j) last[j]=0,rest[j].clear(),S.insert(0);
		for(int j=1;j<=_;++j) rest[qwq[j].c].insert(qwq[j].y);
		for(int j=1;j<pos;++j)
		{
			while(p<_&&qwq[p+1].y<t[j+1])
			{
				++p;
				auto it=S.find(last[qwq[p].c]);
				assert(it!=S.end());
				S.erase(it);
				last[qwq[p].c]=qwq[p].y+1;
				S.insert(last[qwq[p].c]);
			}
			val[j]=*S.begin();
		}
		tr.node_cnt=0;
		tr.build(1,pos-1);
		int tmp=0;
		for(int j=n;j>=i;--j)
		{
			add(tmp,1ll*(a[j+1].x-a[j].x)*tr.Query()%mod);
			rest[a[j].c].erase(rest[a[j].c].find(a[j].y));
			auto it=rest[a[j].c].lower_bound(a[j].y);
			int R=it==rest[a[j].c].end()?pos-1:(std::lower_bound(t+1,t+pos+1,*it)-t-1);
			int val=it==rest[a[j].c].begin()?0:(*(--it)+1);
			int __=std::lower_bound(t+1,t+pos+1,a[j].y)-t;
			if(__>R) continue;
			int _L=tr.find(__,R,1,pos-1,1,val);
			if(_L) ++_L;
			else _L=__;
			if(_L<=R) tr.Update(_L,R,1,pos-1,1,val);
		}
		add(ans,1ll*tmp*(a[i].x-a[i-1].x)%mod);
	}
	printf("%d\n",ans);
	return 0;
}