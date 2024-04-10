#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[11111];
bool f;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		f = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i + 1]) f = 1;
		}
		if (f) printf("YES\n");
		else printf("NO\n");
	}
	return Accepted;
}