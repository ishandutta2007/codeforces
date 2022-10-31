#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,tot;
int c[1000];
int sum(int n)
{
	int m=0;
	while (n) m+=n%10,n/=10;
	return m;
}
int main()
{
	scanf("%d",&n);
	for (int i=max(n-100,1);i<=n;i++)
	if (sum(i)+i==n) c[++tot]=i;
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d\n",c[i]);
	return 0;
}