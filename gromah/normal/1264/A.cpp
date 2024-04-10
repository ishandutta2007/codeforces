#include <cstdio>
#include <algorithm>
using namespace std;
#define N 400000 + 5

int Case, n, sz, g, s, b, A[N], S[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", A + i);
		sz = 0;
		for (int l = 1, r; l <= n; l = r)
		{
			for (r = l; r <= n && A[l] == A[r]; r ++) ;
			S[++ sz] = r - l;
		}
		g = S[1];
		int l = 2;
		for (s = 0; s <= g && l <= sz; l ++)
			s += S[l];
		for (b = 0; b <= g && l <= sz; l ++)
			b += S[l];
		if (g < s && g < b && (g + s + b) * 2 <= n)
		{
			for (; l <= sz && (g + s + b + S[l]) * 2 <= n; l ++)
				b += S[l];
			printf("%d %d %d\n", g, s, b);
		}
		else puts("0 0 0");
	}
	return 0;
}