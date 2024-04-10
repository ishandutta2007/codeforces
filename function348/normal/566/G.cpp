#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
int n,m,x,y,num;
PII a[N],b[N],c[N];
double slope(PII a,PII b) { return 1.0*(b.SC-a.SC)/(b.FR-a.FR);}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].FR,&b[i].SC);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int num=0;
	for (int i=1;i<=m;i++) 
	{
		while (num  &&c[num].FR<=b[i].FR&&c[num].SC<=b[i].SC) num--;
		while (num>1&&slope(c[num-1],c[num])<=slope(c[num],b[i])) num--;
		c[++num]=b[i];
	}
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i].FR>=c[num].FR||a[i].SC>=c[1].SC)
		{
			flag=1;continue;
		}
		if (a[i].FR<c[1].FR&&a[i].FR<c[1].SC) continue;
		if (a[i].FR<c[num].FR&&a[i].FR<c[num].SC) continue;
		int l=1,r=num;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			if (c[mid].FR<=a[i].FR) l=mid;else r=mid-1;
		}
		if (c[l].FR==a[i].FR)
		{
			if (c[l].SC<=a[i].SC) flag=1;
			continue;
		}
		if (slope(c[l],a[i])>=slope(a[i],c[l+1])) flag=1;
	}
	if (flag) printf("Max\n");else printf("Min\n");
	return 0;
}