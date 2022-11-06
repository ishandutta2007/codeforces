#include <iostream>
#include <cstdio>

int main()
{
	const int mod = 1000003;
	int n;
	scanf("%d", &n);
	int ret = 1;
	for (int i = 0; i < n-1; i++)
		ret = (3*ret)%mod;
	printf("%d\n", ret);
	return 0;
}