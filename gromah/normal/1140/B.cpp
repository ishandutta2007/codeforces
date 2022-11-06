#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int Case, n;
char s[N];

int Check1()
{
	for (int i = 0; i < n; i ++)
		if (s[i] == '>')
			return i;
	return n - 1;
}

int Check2()
{
	for (int i = n - 1; ~i; i --)
		if (s[i] == '<')
			return n - 1 - i;
	return n - 1;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%s", &n, s);
		printf("%d\n", min(Check1(), Check2()));
	}
	return 0;
}