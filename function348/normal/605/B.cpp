#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
using namespace std;
struct PII { int k,i,id;};
const int N=100010;
int n,m;
PII a[N];
int ans1[N],ans2[N];
int cmp(PII a,PII b) { return a.k<b.k||(a.k==b.k&&a.i>b.i);}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i].k,&a[i].i),a[i].id=i;
	sort(a+1,a+1+m,cmp);
	int now=1,k1=2,k2=3,flag=0;
	for (int i=1;i<=m;i++)
	if (a[i].i)
	{
		now++;
		ans1[a[i].id]=1,ans2[a[i].id]=now;
		if (now>n) flag=1;
	}
	else
	{
		if (k2<=now)
		{
			ans1[a[i].id]=k1,ans2[a[i].id]=k2;
			if (k1+1==k2) k1=2,k2++;
			else k1++;
		}
		else flag=1;
	}
	if (flag) printf("-1\n");else
		for (int i=1;i<=m;i++) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}