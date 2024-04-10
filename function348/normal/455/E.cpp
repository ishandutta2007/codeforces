#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=100010;
int n,m;
int a[N],s[N];
vector<PII> q[N*4];
PII u[N],w[N];
double slope(PII a,PII b) { return 1.0*(a.SC-b.SC)/(a.FR-b.FR);}
void build(int i,int l,int r)
{
	int t=-1;
	for (int j=l;j<=r;j++) w[++t]=MP(a[j],a[j]*j-s[j]);
	sort(w,w+1+t);
	t=-1;
	for (int j=0;j<=r-l;j++)
	{
		PII tmp=w[j];
		if (u[t].FR==tmp.FR&&t>=0) continue;
		while (t>0&&(slope(u[t-1],u[t])>=slope(u[t],tmp)||u[t].SC>=tmp.SC)) t--;
		u[++t]=tmp;
	}
	for (int j=0;j<=t;j++) q[i].push_back(u[j]);
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
int operator * (PII a,int b) { return -a.FR*b+a.SC;}
int get(int i,int k)
{
	int l=0,r=q[i].size()-1;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (q[i][mid]*k>q[i][mid+1]*k) l=mid+1;else r=mid;
	}
	return q[i][l]*k;
}
int query(int i,int l,int r,int ll,int rr,int x)
{
	if (ll<=l&&r<=rr) return get(i,x);
	int mid=(l+r)>>1,res=2000000000;
	if (ll<=mid) res=min(res,query(i*2,l,mid,ll,rr,x));
	if (rr> mid) res=min(res,query(i*2+1,mid+1,r,ll,rr,x));
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",s[y]+query(1,1,n,y-x+1,y,y-x));
	}
	return 0;
}