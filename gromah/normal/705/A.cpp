#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		if (i & 1) printf("I hate ");
			else printf("I love ");
		if (i != n) printf("that ");
			else puts("it");
	}
	return 0;
}