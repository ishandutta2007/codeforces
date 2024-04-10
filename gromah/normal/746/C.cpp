#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int s, x1, x2, t1, t2, p, d;

inline int Solve()
{
	if (d == 1)
	{
		if (p <= x2)
		{
			if (p <= x1 && x1 <= x2) return t1 * (x2 - p);
			else if (x1 > x2) return t1 * (2 * s - p - x2);
			else if (x1 < p) return t1 * (2 * s + x2 - p);
		}
		else
		{
			if (x1 >= x2) return t1 * (2 * s - p - x2);
			else return t1 * (2 * s - p + x2);
		}
	}
	else
	{
		if (p >= x2)
		{
			if (p >= x1 && x1 >= x2) return t1 * (p - x2);
			else if (x1 < x2) return t1 * (x2 + p);
			else if (x1 > p) return t1 * (2 * s + p - x2);
		}
		else
		{
			if (x1 <= x2) return t1 * (p + x2);
			else return t1 * (2 * s - x2 + p);
		}
	}
}

int main()
{
	scanf("%d%d%d", &s, &x1, &x2);
	scanf("%d%d", &t1, &t2);
	scanf("%d%d", &p, &d);
	printf("%d\n", min(t2 * abs(x2 - x1), Solve()));
	return 0;
}