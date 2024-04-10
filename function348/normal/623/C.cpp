#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define FR first
#define SC second
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
typedef long long LL;
int n;
PII a[N];
int yi1[N],yi2[N],ya1[N],ya2[N];
long long ans;
long long sqr(int n) { return 1LL*n*n;}
int check(LL pd)
{
	int mid=sqrt(pd);
	int p=1;
	LL d=1e+18;
	for (int i=1;i<=n;i++)
	{
		int R=min(a[i].FR+mid,-a[i].FR);
		if (R<a[i].FR) break;
		while (a[p+1].FR<=R&&p<n) p++;
		while (a[p].FR>R&&p>i) p--;
		int ymin=min(yi1[i-1],yi2[p+1]);
		int ymax=max(ya1[i-1],ya2[p+1]);
		if (i==1&&p==n) return 1;
		d=min(d,max(sqr(max(-ymin,ymax))+sqr(a[i].FR),sqr(ymax-ymin)));
	}
//	cout<<d<<endl;
	if (d<=pd) return 1;
	return 0;
}
void doit()
{
	sort(a+1,a+1+n);
	yi1[0]=yi2[n+1]=1e+9;
	ya1[0]=ya2[n+1]=-1e+9;
	for (int i=1;i<=n;i++) yi1[i]=min(yi1[i-1],a[i].SC);
	for (int i=n;i>=1;i--) yi2[i]=min(yi2[i+1],a[i].SC);
	for (int i=1;i<=n;i++) ya1[i]=max(ya1[i-1],a[i].SC);
	for (int i=n;i>=1;i--) ya2[i]=max(ya2[i+1],a[i].SC);
	LL l=0,r=1e+18;
	while (l<r)
	{
		LL mid=(l+r)/2;
		if (check(mid)) r=mid;else l=mid+1;
	}
	ans=min(ans,l);
}
int main()
{
	scanf("%d",&n);
	ans=1e+18;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	doit();
	for (int i=1;i<=n;i++) a[i].FR*=-1;
	doit();
	int y1=1e+9,y2=-1e+9;
	for (int i=1;i<=n;i++) y1=min(y1,a[i].SC),y2=max(y2,a[i].SC);
	ans=min(ans,sqr(y2-y1));
	cout<<ans<<endl;
	return 0;
}