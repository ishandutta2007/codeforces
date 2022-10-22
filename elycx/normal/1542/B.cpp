#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
long long n, a, b;
int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%lld%lld%lld", &n, &a, &b);
		long long tmp = 1;
		int flag = 0;
		for (int j = 1; j <= 35; j++)
		{
			if(tmp > n) break;
			if((n - tmp) % b == 0) flag = 1;
			tmp *= a;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}