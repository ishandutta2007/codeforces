#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, len_s, len_t, Sum_s[N], Sum_t[N], Last_s[N], Last_t[N];
char S[N], T[N];

bool Judge(int ret, int x, int y, bool op)
{
	if (ret & 1) return 0;
	if (x < y) return 0;
	if (!ret) return (x - y) % 3 == 0;
	if (op)
	{
		for (int i = 1; i <= 3 && i <= x; i ++)
			if (Judge(ret - 2, x - i, y, 0)) return 1;
		return 0;
	}
	if ((x - y) % 3 == 0) return 1;
	else if (ret >= 2 && x >= y + 1 && (x - y - 1) % 3 == 0) return 1;
	else if (ret >= 2 && x >= y + 2 && (x - y - 2) % 3 == 0) return 1;
	return 0;
}

int main()
{
	scanf("%s%s", S + 1, T + 1);
	len_s = strlen(S + 1);
	len_t = strlen(T + 1);
	for (int i = 1; i <= len_s; i ++)
	{
		Sum_s[i] = Sum_s[i - 1] + (S[i] != 'A');
		Last_s[i] = (S[i] != 'A') ? 0 : Last_s[i - 1] + 1;
	}
	for (int i = 1; i <= len_t; i ++)
	{
		Sum_t[i] = Sum_t[i - 1] + (T[i] != 'A');
		Last_t[i] = (T[i] != 'A') ? 0 : Last_t[i - 1] + 1;
	}
	scanf("%d", &n);
	for (int i = 1, a, b, c, d; i <= n; i ++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int u = Sum_s[b] - Sum_s[a - 1];
		int v = Sum_t[d] - Sum_t[c - 1];
		bool ok = 1;
		if (u > v) ok = 0;
		if (u + v & 1) ok = 0;
		if (!Judge(v - u, min(Last_s[b], b - a + 1), min(Last_t[d], d - c + 1), Last_s[b] > b - a)) ok = 0;
		putchar('0' + ok);
	}
	return 0;
}