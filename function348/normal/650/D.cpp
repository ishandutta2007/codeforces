#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=400010,NN=N*30,C=1000000000,mo=1000000007;
typedef pair<int,int> PII;
struct Edge {int id,z,ne;};
int lc[NN],rc[NN];
PII t[NN];
int num,n,m;
int a[N],p[N],q[N],ans[N],must[N];
Edge e[N];int last[N];
PII operator + (PII a,PII b) 
{
	if (a.FR==b.FR) 
	{
		int tmp=a.SC+b.SC;
		if (tmp>=mo) tmp-=mo;
		return MP(a.FR,tmp);
	}
	if (a.FR>b.FR) return a;
	if (a.FR<b.FR) return b;
}
PII query(int i,int l,int r,int ll,int rr)
{
//	if (r<=10)printf("%d %d %d\n",i,l,r);
	if (ll>rr) return MP(0,1);
	if (i==0 ) return MP(0,1);
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)>>1;
	PII res=MP(0,1);
	if (ll<=mid&&lc[i]) res=res+query(lc[i],l,mid,ll,rr);
	if (rr> mid&&rc[i]) res=res+query(rc[i],mid+1,r,ll,rr);
	return res;
}
void change(int &i,int l,int r,int k,PII d)
{
	if (i==0) i=++num;
	int mid=(l+r)>>1;
	if (l==r)
	{
		t[i]=t[i]+d;
		return;
	}
	if (k<=mid) change(lc[i],l,mid,k,d);
	if (k> mid) change(rc[i],mid+1,r,k,d);
	t[i]=MP(-1,1);
	if (lc[i]) t[i]=t[i]+t[lc[i]];
	if (rc[i]) t[i]=t[i]+t[rc[i]];
}
void add(int x,int id,int z)
{
	e[++num]=(Edge){id,z,last[x]};last[x]=num;
}
void clear()
{
	for (int i=1;i<=num;i++) lc[i]=rc[i]=0,t[i]=MP(0,0);
	num=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,i,y);
	}
	
	num=1;
	clear();
	for (int i=1;i<=n;i++) 
	{
		
		PII x=query(1,1,C,1,a[i]-1);
		for (int j=last[i];j;j=e[j].ne) ans[e[j].id]+=query(1,1,C,1,e[j].z-1).FR;
		if (x.FR==0) x.SC=1;x.FR++;
//		printf("%d %d\n",x.FR,x.SC);
		p[i]=x.SC;q[i]=x.FR;
		int t=1;
		change(t,1,C,a[i],x);
	}
	int now=t[1].FR,cnt=t[1].SC;
//	for (int i=1;i<=n;i++) printf("%d ",ans[i]);printf("\n");
	clear();
	for (int i=n;i>=1;i--)
	{
		PII x=query(1,1,C,a[i]+1,C);
		if (x.FR==0) x.SC=1;x.FR++;
		p[i]=1LL*p[i]*x.SC%mo;q[i]+=x.FR-1;
		for (int j=last[i];j;j=e[j].ne) 
		{
			ans[e[j].id]+=query(1,1,C,e[j].z+1,C).FR;
			must[e[j].id]=(p[i]==cnt&&q[i]==now);
		}
		int t=1;
		change(t,1,C,a[i],x);
	}
	for (int i=1;i<=m;i++)
	{
		ans[i]++;
		if (must[i]) printf("%d\n",max(now-1,ans[i]));
		else printf("%d\n",max(now,ans[i]));
	}
	return 0;
}