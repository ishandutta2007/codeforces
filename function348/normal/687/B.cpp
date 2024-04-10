#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000100;
int n,m,ok;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);
	ok=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=m;i++)
	if (m%i==0)
	{
		int r=1;
		while (m%i==0) m/=i,r*=i;
		int f=0;
		for (int j=1;j<=n;j++)
		if (a[j]%r==0) f=1;
		if (!f) ok=0;
	}
	printf(ok?"YES\n":"NO\n");
	return 0;
}