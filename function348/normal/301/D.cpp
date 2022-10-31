#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=200010;
typedef pair<int,int> PII;
struct Ques{int l,r,id;};
int n,m,num;
int a[N],b[N],bit[N];
PII c[N*20];
Ques q[N];
int ans[N];
int cmp1(PII a,PII b) { return a.SC<b.SC;}
int cmp2(Ques a,Ques b) { return a.r<b.r;}
void C(int i,int d) { for (;i<=n;i+=i&-i) bit[i]+=d;}
int  Q(int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[a[i]]=i;
	for (int i=1;i<=n;i++)	if (b[i])
	for (int j=i;j<=n;j+=i)	if (b[j])
	{
		c[++num]=MP(min(b[i],b[j]),max(b[i],b[j]));
	}
	sort(c+1,c+1+num,cmp1);
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+1+m,cmp2);
	for (int i=1,j=1;i<=m;i++)
	{
		while (j<=num&&c[j].SC<=q[i].r)
		{
			C(1,1);C(c[j].FR+1,-1);
			j++;
		}
		ans[q[i].id]=Q(q[i].l);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}