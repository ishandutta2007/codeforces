#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
long long f[N];
int c[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	f[1]=c[1];
	for (int i=2;i<=100000;i++)
	f[i]=max(f[i-1],1LL*i*c[i]+f[i-2]);
	printf("%lld\n",f[100000]);
	return 0;
}