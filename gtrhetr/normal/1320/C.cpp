#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct hhhh { int x,y,z; }h[200010];

struct node { int x,y; }a[200010],b[200010];

vector<pii> v[200010];

int h1[200010],h2[200010],n,m,p;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const node &x,const node &y) { return x.x<y.x; }

ll mx[800010],tag[800010];

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { tag[o]+=hh;mx[o]+=hh;return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	mx[o]=max(mx[o<<1],mx[o<<1|1])+tag[o];
}

inline void build(int o,int l,int r)
{
	if (l==r) { mx[o]=-b[l].y;return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}

int main()
{
	n=rd();m=rd();p=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	for (int i=1;i<=m;i++) b[i].x=rd(),b[i].y=rd();
	for (int i=1;i<=p;i++) h[i].x=rd(),h[i].y=rd(),h[i].z=rd();
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp);
	for (int i=1;i<=n;i++) h1[i]=a[i].x;
	for (int i=1;i<=m;i++) h2[i]=b[i].x;
	build(1,1,m);
	for (int i=1;i<=p;i++)
	{
		int now1=upper_bound(h1+1,h1+n+1,h[i].x)-h1,now2=upper_bound(h2+1,h2+m+1,h[i].y)-h2;
		if (now2<=m) v[now1].push_back(pii(now2,h[i].z));
	}
	ll ans=-2333333333333333333LL;
	for (int i=1;i<=n;i++)
	{
		for (pii hh:v[i]) modify(1,1,m,hh.first,m,hh.second);
		ans=max(ans,mx[1]-a[i].y);
	}
	printf("%lld\n",ans);
	return 0;
}