#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int cnt0 = 0, cnt1 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
		{
			scanf("%d", &x);
			if(x % 2 == 0) cnt0++;
			else cnt1++;
		}
		if(cnt0 != n) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}