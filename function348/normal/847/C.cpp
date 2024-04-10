#include<cstdio>
#include<iostream>
using namespace std;
int a[1000],c[1000],v[1000];
int n;
long long k;
int main()
{
	cin>>n>>k;
	if (k>1LL*n*(n-1)/2) { printf("Impossible\n");return 0;}
	for (int i=1;i<=n;i++)
	if (1LL*i*(i+1)>k*2) 
	{
		k-=1LL*i*(i-1)/2;
		for (int j=1;j<=i;j++) putchar('(');
		for (int j=i;j>k;j--) putchar(')');
		if (k>0) 
		{
			printf("()");
		for (int j=k;j>=1;j--) putchar(')');
		for (int j=i+2;j<=n;j++) printf("()");
		}
		else
		for (int j=i+1;j<=n;j++) printf("()");
		break;
	}
	return 0;
}