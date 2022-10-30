// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
char s[N];
int L[N],R[N],U[N],D[N];
void get(int *a)
{
	int l=read_str(s+1);
	for(int i=1;i<=l;++i) a[i]=s[i]=='R';
}
struct mat{
	int a,b,c,d;
	inline mat operator * (const mat &o)const
	{
		return (mat){min(a+o.a,b+o.c),min(a+o.b,b+o.d),min(c+o.a,d+o.c),min(c+o.b,d+o.d)};
	}
};
int n,m;
inline mat get(int a,int b)
{
	return (mat){a+b,m+2-a-b,m+a+b,2-a-b};
}
struct SEG_TR{
	struct Node{
		int ls,rs;
		int sum[2];
		bool tag;
	}f[N<<1];
	int node_cnt;
	inline void pushup(int x)
	{
		f[x].sum[0]=f[f[x].ls].sum[0]+f[f[x].rs].sum[0];
		f[x].sum[1]=f[f[x].ls].sum[1]+f[f[x].rs].sum[1];
	}
	int build(int l,int r,int *arr)
	{
		int cur=++node_cnt;
		f[cur].tag=0;
		if(l==r)
		{
			f[cur].sum[0]=arr[l]==0;
			f[cur].sum[1]=arr[l]==1;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		return pushup(cur),cur;
	}
	inline void upd(int x)
	{
		std::swap(f[x].sum[0],f[x].sum[1]);
		f[x].tag^=1;
	}
	inline void pushdown(int x)
	{
		if(f[x].tag) upd(f[x].ls),upd(f[x].rs),f[x].tag=0;
	}
	void Update(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur);
			return;
		}
		pushdown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		pushup(cur);
	}
}_[2];
struct seg_tr{
	struct Node{
		int ls,rs;
		mat v0,v1,v2,v3;
		bool t0,t1;
	}f[N<<1];
	int node_cnt;
	inline void pushup(int x)
	{
		f[x].v0=f[f[x].ls].v0*f[f[x].rs].v0;
		f[x].v1=f[f[x].ls].v1*f[f[x].rs].v1;
		f[x].v2=f[f[x].ls].v2*f[f[x].rs].v2;
		f[x].v3=f[f[x].ls].v3*f[f[x].rs].v3;
	}
	inline void upd(int x,int t)
	{
		if(!t) f[x].t0^=1,std::swap(f[x].v0,f[x].v1),std::swap(f[x].v2,f[x].v3);
		else f[x].t1^=1,std::swap(f[x].v0,f[x].v2),std::swap(f[x].v1,f[x].v3);
	}
	inline void pushdown(int x)
	{
		if(f[x].t0) upd(f[x].ls,0),upd(f[x].rs,0),f[x].t0=0;
		if(f[x].t1) upd(f[x].ls,1),upd(f[x].rs,1),f[x].t1=0;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].t0=f[cur].t1=0;
		if(l==r)
		{
			f[cur].v0=get(L[l],R[l]);
			f[cur].v1=get(1-L[l],R[l]);
			f[cur].v2=get(L[l],1-R[l]);
			f[cur].v3=get(1-L[l],1-R[l]);
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return pushup(cur),cur;
	}
	void Update(int L,int R,int t,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur,t);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(cur);
		if(L<=mid) Update(L,R,t,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,t,mid+1,r,f[cur].rs);
		pushup(cur);
	}
	inline mat Query(){return f[1].v0;}
}tr;
char opt[N];
int X[N],Y[N];
int ans[N];
int main()
{
	int q;read(n,m,q);
	get(L);get(R);get(U);get(D);
	for(int i=1;i<=q;++i)
	{
		char ch=getchar();
		while(ch!='L'&&ch!='R'&&ch!='D'&&ch!='U') ch=getchar();
		opt[i]=ch;
		read(X[i],Y[i]);
	}
	memset(ans,63,sizeof(ans));
	for(int __=0;__<2;++__)
	{
		if(__)
		{
			std::swap(n,m),std::swap(L,U),std::swap(R,D);
			for(int i=1;i<=q;++i)
			{
				if(opt[i]=='U') opt[i]='L';
				else if(opt[i]=='D') opt[i]='R';
				else if(opt[i]=='L') opt[i]='U';
				else if(opt[i]=='R') opt[i]='D';
			}
		}
		tr.node_cnt=_[0].node_cnt=_[1].node_cnt=0;
		tr.build(1,n);
		_[0].build(1,m,U);
		_[1].build(1,m,D);
		mat tmp=(mat){_[0].f[1].sum[1],_[0].f[1].sum[0],inf,inf}*tr.Query();
		chmin(ans[0],min(tmp.a+_[1].f[1].sum[1],tmp.b+_[1].f[1].sum[0]));
		for(int i=1;i<=q;++i)
		{
			if(opt[i]=='U') _[0].Update(X[i],Y[i],1,m,1);
			else if(opt[i]=='D') _[1].Update(X[i],Y[i],1,m,1);
			else if(opt[i]=='L') tr.Update(X[i],Y[i],0,1,n,1);
			else tr.Update(X[i],Y[i],1,1,n,1);
			mat tmp=(mat){_[0].f[1].sum[1],_[0].f[1].sum[0],inf,inf}*tr.Query();
			chmin(ans[i],min(tmp.a+_[1].f[1].sum[1],tmp.b+_[1].f[1].sum[0]));
		}
	}
	for(int i=0;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}