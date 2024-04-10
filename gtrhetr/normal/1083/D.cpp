#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

struct hhhh
{
	int l,r,v;
	hhhh() {}
	hhhh(int l1,int r1,int v1):l(l1),r(r1),v(v1) {}
}st1[100010],st2[100010];

struct node
{
	ll mn,mx,mn1,sum,tag1,tag2;
	node() {}
	node(ll mn1,ll mx1,ll mn11,ll sum1,ll tag11,ll tag21):mn(mn1),mx(mx1),mn1(mn11),sum(sum1),tag1(tag11),tag2(tag21) {}
}t[400010];

unordered_map<int,int> mp;

int num[100010],mn[100010],mx[100010],n,top1,top2;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll calc(int l,int r) { return (ll)(l+r)*(r-l+1)/2%mod; }

inline node operator +(const node &x,const node &y) { return node(pls(x.mn,y.mn),pls(x.mx,y.mx),pls(x.mn1,y.mn1),pls(x.sum,y.sum),0,0); }

inline void gao1(int o,int l,int r,ll hh)
{
	t[o].mn=pls(t[o].mn,hh*(r-l+1)%mod);
	t[o].mn1=pls(t[o].mn1,calc(l,r)*hh%mod);
	t[o].sum=pls(t[o].sum,t[o].mx*hh%mod);
	t[o].tag1=pls(t[o].tag1,hh);
}

inline void gao2(int o,int l,int r,ll hh)
{
	t[o].mx=pls(t[o].mx,hh*(r-l+1)%mod);
	t[o].sum=pls(t[o].sum,t[o].mn*hh%mod);
	t[o].tag2=pls(t[o].tag2,hh);
}

inline void pushdown(int o,int l,int r)
{
	int mid=(l+r)>>1;
	if (t[o].tag1) gao1(o<<1,l,mid,t[o].tag1),gao1(o<<1|1,mid+1,r,t[o].tag1),t[o].tag1=0;
	if (t[o].tag2) gao2(o<<1,l,mid,t[o].tag2),gao2(o<<1|1,mid+1,r,t[o].tag2),t[o].tag2=0;
}

inline void build(int o,int l,int r)
{
	t[o]=node(0,0,0,0,0,0);
	if (l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

inline void modify1(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { gao1(o,l,r,hh);return; }
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if (x<=mid) modify1(o<<1,l,mid,x,y,hh);
	if (y>mid) modify1(o<<1|1,mid+1,r,x,y,hh);
	t[o]=t[o<<1]+t[o<<1|1];
}

inline void modify2(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { gao2(o,l,r,hh);return; }
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if (x<=mid) modify2(o<<1,l,mid,x,y,hh);
	if (y>mid) modify2(o<<1|1,mid+1,r,x,y,hh);
	t[o]=t[o<<1]+t[o<<1|1];
}

inline node query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return t[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;node res(0,0,0,0,0,0);
	if (x<=mid) res=res+query(o<<1,l,mid,x,y);
	if (y>mid) res=res+query(o<<1|1,mid+1,r,x,y);
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	top1=top2=0;
	for (int i=1;i<=n;i++) mx[i]=mp[num[i]],mp[num[i]]=i;
	for (int i=1;i<=n;i++) if (mx[i]) mn[mx[i]]=i;
	for (int i=1;i<=n;i++) if (!mn[i]) mn[i]=n+1;
	for (int i=1;i<=n;i++) mx[i]++,mn[i]--;
	build(1,1,n);
	int lst=1;
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		for (;top1>1&&st1[top1].v>mn[i];top1--) modify1(1,1,n,st1[top1].l,st1[top1].r,mns(mn[i],st1[top1].v));
		top1++;st1[top1]=hhhh(st1[top1-1].r+1,i,mn[i]);
		for (;top2>1&&st2[top2].v<mx[i];top2--) modify2(1,1,n,st2[top2].l,st2[top2].r,mns(mx[i],st2[top2].v));
		top2++;st2[top2]=hhhh(st2[top2-1].r+1,i,mx[i]);
		modify1(1,1,n,i,i,mn[i]);
		modify2(1,1,n,i,i,mx[i]);
		lst=max(lst,mx[i]+1);
		node now=query(1,1,n,lst,i);
		ans=pls(ans,mns(pls(now.mn1,now.mx*i%mod),pls(now.sum,calc(lst,i)*i%mod)));
	}
	printf("%lld\n",ans);
	return 0;
}