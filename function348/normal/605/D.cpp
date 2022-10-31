#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=300010;
typedef pair<int,int> PII;
typedef pair<PII,int> rec;
queue<rec> Q;
struct recc{int a,b,c,d,e;};
int n;
int f[N],g[N];
PII t[N*4];
recc a[N];
void print(int n)
{
	if (f[n]!=0) print(g[n]);
	printf("%d ",a[n].e);
}
void build(int i,int l,int r)
{
	int mid=(l+r)>>1;
	if (l==r)
	{
		t[i]=MP(a[l].b,l);
		return;
	}
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i]=min(t[i*2],t[i*2+1]);
}
void change(int i,int l,int r,int k)
{
	if (l==r)
	{
		t[i]=MP(2000000000,0);
		return;
	}
	int mid=(l+r)>>1;
	if (k<=mid) change(i*2,l,mid,k);
	if (k> mid) change(i*2+1,mid+1,r,k);
	t[i]=min(t[i*2],t[i*2+1]);
}
PII query(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)>>1;
	PII res=MP(2000000000,0);
	if (ll<=mid) res=min(res,query(i*2,l,mid,ll,rr));
	if (rr> mid) res=min(res,query(i*2+1,mid+1,r,ll,rr));
	return res;
}
int cmp(recc a,recc b) { return a.a<b.a||(a.a==b.a&&a.b<b.b);}
int find(int p)
{
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (a[mid].a<=p) l=mid;else r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d),a[i].e=i;
	int tmpx=a[n].a,tmpy=a[n].b;
	sort(a+1,a+1+n,cmp);
	build(1,1,n);
	for (int i=1;i<=n;i++) f[i]=-1;
	for (int i=1;i<=n;i++)
	if (a[i].a==0&&a[i].b==0) 
		Q.push(MP(MP(a[i].c,a[i].d),i)),f[i]=0,change(1,1,n,i);
	while (!Q.empty())
	{
		rec tmp=Q.front();Q.pop();
		int r=find(tmp.FR.FR);
		while (1)
		{
			PII now=query(1,1,n,1,r);
	//		printf("%d %d %d %d\n",tmp.FR.FR,r,now.FR,now.SC);
	//		while (1);
			if (now.FR<=tmp.FR.SC)
			{
				change(1,1,n,now.SC);
				Q.push(MP(MP(a[now.SC].c,a[now.SC].d),now.SC));
				f[now.SC]=f[tmp.SC]+1;
				g[now.SC]=tmp.SC;
			}
			else break;
		}
	}
	int aim=0;
	for (int i=1;i<=n;i++)
	if (a[i].e==n) aim=i;
	if (f[aim]==-1) 
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",f[aim]+1);
	print(aim);
	return 0;
}