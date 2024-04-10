#include <cstdio>
#include <algorithm>
using namespace std;

int Case, n;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
			{
				if (i == n || i != j)
					printf("()");
				else printf("(())"), j ++;
			}
			puts("");
		}
	}
	return 0;
}