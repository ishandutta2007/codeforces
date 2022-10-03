#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define inf 2333333333333333333LL

pii h1[400010],h2[400010];

ll c[200010];
ll a[400010],b[400010];
int id1[200010],id2[200010],to[200010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void gao(int l,int r,ll x)
{
	if (l>r) return;
	l=(l%n+n)%n;r=(r%n+n)%n;
	if (l<=r) c[l]+=x,c[r+1]-=x;
	else c[0]+=x,c[r+1]-=x,c[l]+=x;
}

int main()
{
	m=rd();n=rd();
	for (int i=1;i<=n;i++) h1[i].first=rd(),h1[i].second=i;
	for (int i=1;i<=n;i++) h2[i].first=rd(),h2[i].second=i;
	sort(h1+1,h1+n+1);
	sort(h2+1,h2+n+1);
	for (int i=1;i<=n;i++) a[i]=h1[i].first,b[i]=h2[i].first;
	for (int i=1;i<=n;i++) a[i+n]=h1[i].first+m,b[i+n]=h2[i].first+m;
	int now,now1;
	now=now1=1;
	for (int i=1;i<=n;i++) if (a[i]+m/2<=m)
	{
		while (now<=n&&a[i]+m/2>=b[now]) now++;
		while (now1<=n&&a[i]>b[now1]) now1++;
		int l=now1,r=now-1;
		gao(l-i,r-i,-a[i]);
		gao(1-i,l-1-i,a[i]);
		gao(r+1-i,n-i,a[i]+m);
	}
	now=now1=1;
	for (int i=1;i<=n;i++) if (a[i]+m/2>m)
	{
		while (now<=n&&a[i]+m/2>=b[now]+m) now++;
		while (now1<=n&&a[i]>b[now1]) now1++;
		int l=now-1,r=now1;
		gao(1-i,l-i,-a[i]);
		gao(l+1-i,r-1-i,a[i]);
		gao(r-i,n-i,-a[i]);
	}
	
	int hh=(m%2==0)?m/2-1:m/2;
	
	now=now1=1;
	for (int i=1;i<=n;i++) if (b[i]+hh<=m)
	{
		while (now<=n&&b[i]+hh>=a[now]) now++;
		while (now1<=n&&b[i]>=a[now1]) now1++;
		int l=now1,r=now-1;
		gao(i-r,i-l,-b[i]);
		gao(i-(l-1),i-1,b[i]);
		gao(i-n,i-(r+1),b[i]+m);
	}
	now=now1=1;
	for (int i=1;i<=n;i++) if (b[i]+hh>m)
	{
		while (now<=n&&b[i]+hh>=a[now]+m) now++;
		while (now1<=n&&b[i]>=a[now1]) now1++;
		int l=now-1,r=now1;
		gao(i-l,i-1,-b[i]);
		gao(i-(r-1),i-(l+1),b[i]);
		gao(i-n,i-r,-b[i]);
	}
	
	for (int i=1;i<n;i++) c[i]+=c[i-1];
	ll ans=inf;int id=0;
	for (int i=0;i<n;i++) if (c[i]<ans) ans=c[i],id=i;
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) to[h1[i].second]=h2[(i+id-1)%n+1].second;
	for (int i=1;i<=n;i++) printf("%d ",to[i]);
	puts("");
	return 0;
}