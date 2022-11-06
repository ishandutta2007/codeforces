#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, m;
char s[N], t[N];

bool Check()
{
	int pos = 0;
	for (; pos < n; pos ++)
		if (s[pos] == '*') break;
	if (pos == n)
	{
		if (n != m) return 0;
		for (int i = 0; i < n; i ++)
			if (s[i] != t[i]) return 0;
	}
	else
	{
		if (n - 1 > m) return 0;
		for (int i = 0; i < pos; i ++)
			if (i >= m || s[i] != t[i]) return 0;
		for (int j = 0; n - 1 - j > pos; j ++)
			if (m - 1 - j < 0 || s[n - 1 - j] != t[m - 1 - j]) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s%s", s, t);
	puts(Check() ? "YES" : "NO");
	return 0;
}