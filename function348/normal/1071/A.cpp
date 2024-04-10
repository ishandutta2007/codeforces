#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int N=200010,p=1000000007;
typedef long long LL;
int a[N],b[N];
int n,m;
int main()
{
//	freopen("dividing.in","r",stdin);
//	freopen("dividing.out","w",stdout);
	scanf("%d%d",&n,&m);
	int f=0;
	if (n>m) swap(n,m),f=1;
	int k=1;
	int r=0,s=0;
	while (1LL*k*(k+1)/2<=n+m) k++;k--;
	while (n>=k&&k>0)
	{
		a[++r]=k;n-=k;
		k--;
	}
	if (n>0) a[++r]=n;
	while (k>=1)
	{
		if (k!=n) b[++s]=k;
		k--;
	}
	if (!f)
	{
	printf("%d\n",r);
	for (int i=1;i<=r;i++) printf("%d ",a[i]);cout<<endl;
	printf("%d\n",s);
	for (int i=1;i<=s;i++) printf("%d ",b[i]);cout<<endl;
	}
	else
	{
	printf("%d\n",s);
	for (int i=1;i<=s;i++) printf("%d ",b[i]);cout<<endl;
	printf("%d\n",r);
	for (int i=1;i<=r;i++) printf("%d ",a[i]);cout<<endl;
	}
	return 0;
}

/*
   f[i][j] > j < (i-1-c[i-1]+j)
   */