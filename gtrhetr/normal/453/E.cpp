#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&(-(x)))

struct node
{
	int l,r,t;
	node() {}
	node(int l1,int r1,int t1):l(l1),r(r1),t(t1) {}
};

inline bool operator <(const node &x,const node &y) { return x.l<y.l; }

struct hhhh { int l,r,t,id; }h[500010];

set<node> st;

ll S[100010],M[100010],R[100010],ans[100010],c[100010];
int g[100010],n,m,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll min(const ll &x,const ll &y) { return (x<y)?x:y; }
inline ll max(const ll &x,const ll &y) { return (x>y)?x:y; }

inline set<node>::iterator split(int x)
{
	set<node>::iterator it=st.upper_bound(node(x,0,0));it--;
	if (x==(*it).l) return it;
	node hh=*it;
	st.erase(hh);
	st.insert(node(hh.l,x-1,hh.t));
	return st.insert(node(x,hh.r,hh.t)).first;
}

inline void pre_gao(int l,int r,int t,int id) { for (int i=l;i<=r;i++) ans[id]+=min(S[i]+R[i]*t,M[i]); }

inline bool cmp(const hhhh &x,const hhhh &y) { return x.t<y.t; }

inline bool cmp1(const int &x,const int &y)
{
	if (!R[x]) return false;
	if (!R[y]) return true;
	return (M[x]/R[x]+1)<(M[y]/R[y]+1);
}

ll sum[400010],s[400010],tag[400010];

inline void gao(const int &o,const ll &hh) { sum[o]+=s[o]*hh;tag[o]+=hh; }

inline void pushdown(const int &o)
{
	if (!tag[o]) return;
	gao(o<<1,tag[o]);
	gao(o<<1|1,tag[o]);
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	sum[o]=tag[o]=0;
	if (l==r) { s[o]=R[l];return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}

inline void del(int o,int l,int r,int x)
{
	if (l==r) { s[o]=sum[o]=0;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) del(o<<1,l,mid,x);
	else del(o<<1|1,mid+1,r,x);
	sum[o]=sum[o<<1]+sum[o<<1|1];
	s[o]=s[o<<1]+s[o<<1|1];
}

inline ll query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return sum[o];
	pushdown(o);
	int mid=(l+r)>>1;ll res=0;
	if (x<=mid) res+=query(o<<1,l,mid,x,y);
	if (y>mid) res+=query(o<<1|1,mid+1,r,x,y);
	return res;
}

inline void add(int x,ll y) { for (;x<=n;x+=lowbit(x)) c[x]+=y; }

inline ll query(int x)
{
	ll res=0;
	for (;x;x-=lowbit(x)) res+=c[x];
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) S[i]=rd(),M[i]=rd(),R[i]=rd();
	for (int i=1;i<=n;i++) st.insert(node(i,i,0));
	m=rd();
	for (int i=1;i<=m;i++)
	{
		int t=rd(),l=rd(),r=rd();
		if (r<n) split(r+1);
		for (set<node>::iterator it=split(l);it!=st.end()&&it->l<=r;st.erase(it++))
		{
			if (it->t==0) pre_gao(it->l,it->r,t,i);
			else h[++tt]=(hhhh){it->l,it->r,t-it->t,i};
		}
		st.insert(node(l,r,t));
	}
	sort(h+1,h+tt+1,cmp);
	for (int i=1;i<=n;i++) g[i]=i;
	sort(g+1,g+n+1,cmp1);
	build(1,1,n);
	int now=1;
	for (int i=1;i<=tt;i++)
	{
		for (;now<=n&&R[g[now]]&&M[g[now]]/R[g[now]]+1<=h[i].t;now++)
		{
			del(1,1,n,g[now]);
			add(g[now],M[g[now]]);
		}
		gao(1,h[i].t-h[i-1].t);
		ans[h[i].id]+=query(1,1,n,h[i].l,h[i].r)+query(h[i].r)-query(h[i].l-1);
	}
	for (int i=1;i<=m;i++) print(ans[i]);
	return 0;
}