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

const int N=150005;
int n;
struct node1{
	int v1,c1,v2;
	Finline node1 operator + (const node1 &o)const
	{
		if(o.v1>v1) return (node1){o.v1,o.c1,max(v1,o.v2)};
		else if(o.v1==v1) return (node1){v1,c1+o.c1,max(v2,o.v2)};
		else return (node1){v1,c1,max(v2,o.v1)};
	}
};
struct node2{
	int v1,c1,v2;
	Finline node2 operator + (const node2 &o)
	{
		if(o.v1<v1) return (node2){o.v1,o.c1,min(v1,o.v2)};
		else if(o.v1==v1) return (node2){v1,c1+o.c1,min(v2,o.v2)};
		else return (node2){v1,c1,min(v2,o.v1)};
	}
};
struct seg_tr1{
	struct Node{
		int ls,rs;
		ll sum1,sum2,sum,tag;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].sum1=f[f[x].ls].sum1+f[f[x].rs].sum1;
		f[x].sum2=f[f[x].ls].sum2+f[f[x].rs].sum2;
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	Finline void upd(int cur,int val,int l,int r)
	{
		f[cur].sum2+=1ll*(r-l+1)*val;
		f[cur].sum+=1ll*f[cur].sum1*val;
		f[cur].tag+=val;
	}
	Finline void pushdown(int cur,int l,int r)
	{
		if(f[cur].tag)
		{
			int mid=(l+r)>>1;
			upd(f[cur].ls,f[cur].tag,l,mid);
			upd(f[cur].rs,f[cur].tag,mid+1,r);
			f[cur].tag=0;
		}
	}
	void Update1(int pos,int val,int l,int r,int cur)
	{
		if(l==r)
		{
			f[cur].sum1+=val;
			f[cur].sum+=1ll*val*f[cur].sum2;
			return;
		}
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(pos<=mid) Update1(pos,val,l,mid,f[cur].ls);
		else Update1(pos,val,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	void Update2(int L,int R,int val,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur,val,l,r);
			return;
		}
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update2(L,R,val,l,mid,f[cur].ls);
		if(R>mid) Update2(L,R,val,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	Finline ll Query(){return f[1].sum;}
}tr;
struct seg_tr2{
	struct Node{
		int ls,rs;
		node1 maxx;
		node2 minn;
		int tag1,tag2;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].maxx=f[f[x].ls].maxx+f[f[x].rs].maxx;
		f[x].minn=f[f[x].ls].minn+f[f[x].rs].minn;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].tag1=n+1,f[cur].tag2=0;
		f[cur].maxx=(node1){n+1,0,0};
		f[cur].minn=(node2){0,0,n+1};
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	Finline void upd1(int x,int val)
	{
		chmin(f[x].maxx.v1,val);
		chmin(f[x].tag1,val);
	}
	Finline void upd2(int x,int val)
	{
		chmax(f[x].minn.v1,val);
		chmax(f[x].tag2,val);
	}
	Finline void pushdown(int cur)
	{
		if(f[cur].tag1<n+1) upd1(f[cur].ls,f[cur].tag1),upd1(f[cur].rs,f[cur].tag1),f[cur].tag1=n+1;
		if(f[cur].tag2>0) upd2(f[cur].ls,f[cur].tag2),upd2(f[cur].rs,f[cur].tag2),f[cur].tag2=0;
	}
	void upd_chmin(int L,int R,int l,int r,int cur,int val)
	{
		if(val>=f[cur].maxx.v1) return;
		if(l!=r) pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=l&&r<=R)
		{
			if(val<=f[cur].maxx.v2)
			{
				upd_chmin(L,R,l,mid,f[cur].ls,val);
				upd_chmin(L,R,mid+1,r,f[cur].rs,val);
				pushup(cur);
			}
			else
			{
				if(f[cur].maxx.c1) tr.Update1(f[cur].maxx.v1,-f[cur].maxx.c1,0,n+1,1);
				upd1(cur,val);
				if(f[cur].maxx.c1) tr.Update1(f[cur].maxx.v1,f[cur].maxx.c1,0,n+1,1);
			}
			return;
		}
		if(L<=mid) upd_chmin(L,R,l,mid,f[cur].ls,val);
		if(R>mid) upd_chmin(L,R,mid+1,r,f[cur].rs,val);
		pushup(cur);
	}
	void upd_chmax(int L,int R,int l,int r,int cur,int val)
	{
		if(val<=f[cur].minn.v1) return;
		if(l!=r) pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=l&&r<=R)
		{
			if(val>=f[cur].minn.v2)
			{
				upd_chmax(L,R,l,mid,f[cur].ls,val);
				upd_chmax(L,R,mid+1,r,f[cur].rs,val);
				pushup(cur);
			}
			else
			{
				if(f[cur].minn.c1) tr.Update1(f[cur].minn.v1,f[cur].minn.c1,0,n+1,1);
				upd2(cur,val);
				if(f[cur].minn.c1) tr.Update1(f[cur].minn.v1,-f[cur].minn.c1,0,n+1,1);
			}
			return;
		}
		if(L<=mid) upd_chmax(L,R,l,mid,f[cur].ls,val);
		if(R>mid) upd_chmax(L,R,mid+1,r,f[cur].rs,val);
		pushup(cur);
	}
	void add_val(int pos,int l,int r,int cur)
	{
		if(l==r)
		{
			f[cur].maxx=(node1){n+1,1,0};
			f[cur].minn=(node2){0,1,n+1};
			tr.Update1(n+1,1,0,n+1,1);
			tr.Update1(0,-1,0,n+1,1);
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(pos<=mid) add_val(pos,l,mid,f[cur].ls);
		else add_val(pos,mid+1,r,f[cur].rs);
		pushup(cur);
	}
}__;
int t[N],a[N];
int main()
{
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),t[a[i]]=i;
	tr.build(0,n+1);
	__.build(1,n);
	tr.Update2(n+1,n+1,1,0,n+1,1);
	for(int i=1;i<=n;++i)
	{
		int p=t[i];
		__.add_val(p,1,n,1);
		if(p>1) __.upd_chmin(1,p-1,1,n,1,p);
		if(p<n) __.upd_chmax(p+1,n,1,n,1,p);
		tr.Update2(p,n+1,1,0,n+1,1);
		printf("%lld\n",tr.Query()-i);
	}
	return 0;
}