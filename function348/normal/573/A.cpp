#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		while (a[i]%2==0) a[i]/=2;
		while (a[i]%3==0) a[i]/=3;
	}
	int flag=1;
	for (int i=2;i<=n;i++)
	if (a[i]!=a[i-1]) flag=0;
	printf(flag?"Yes\n":"No\n");
	return 0;
}