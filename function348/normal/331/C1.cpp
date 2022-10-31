#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	while (n)
	{
		int m=n,k=0;
		while (m) k=max(k,m%10),m/=10;
		n-=k;cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}