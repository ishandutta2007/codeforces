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

const int N=1000005;
const int limit=1000001;
struct node{
	int val,cnt;
	Finline node operator + (const node &o)const
	{
		if(val!=o.val) return val<o.val?*this:o;
		return (node){val,cnt+o.cnt};
	}
};
int b[N],c[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].val=f[f[x].ls].val+f[f[x].rs].val;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val=(node){b[l],c[l]};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		pushup(cur);
		return cur;
	}
	Finline void upd(int cur,int C)
	{
		f[cur].val.val+=C;
		f[cur].tag+=C;
	}
	Finline void pushdown(int cur)
	{
		if(f[cur].tag)
		{
			upd(f[cur].ls,f[cur].tag);
			upd(f[cur].rs,f[cur].tag);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur,int C)
	{
		if(L<=l&&r<=R)
		{
			upd(cur,C);
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,C);
		pushup(cur);
	}
	void Modify(int pos,int l,int r,int cur,int C)
	{
		if(l==r)
		{
			f[cur].val.cnt=C;
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(pos<=mid) Modify(pos,l,mid,f[cur].ls,C);
		else Modify(pos,mid+1,r,f[cur].rs,C);
		pushup(cur);
	}
}tr;
int a[N];
void upd(int i,int C)
{
	int L=min(a[i],a[i+1])+1,R=max(a[i],a[i+1]);
	tr.Update(L,R,0,limit,1,C);
}
int main()
{
	int n,q;read(n,q);
	for(int i=1;i<=n;++i) read(a[i]),c[a[i]]=1;
	a[0]=limit,a[n+1]=0;
	for(int i=0;i<=n;++i)
	{
		int L=min(a[i],a[i+1])+1,R=max(a[i],a[i+1]);
		++b[L],--b[R+1];
	}
	for(int i=1;i<=limit;++i) b[i]+=b[i-1];
	b[0]=inf,b[limit]=inf;
	tr.build(0,limit);
	while(q--)
	{
		int x,y;read(x,y);
		upd(x-1,-1),upd(x,-1);
		tr.Modify(a[x],0,limit,1,0),a[x]=y,tr.Modify(a[x],0,limit,1,1);
		upd(x-1,1),upd(x,1);
		node ans=tr.f[1].val;
		printf("%d\n",ans.val==1?ans.cnt:0);
	}
	return 0;
}