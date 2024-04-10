#include <cstdio>
const int da[8] = {0, 1, 0, 0, 1, 1, 0, 1},
          db[8] = {1, 1, 0, 1, 0, 1, 0, 0},
          d0[8] = {0, 0, 0, 1, 0, 1, 1, 1};
bool a0, a1, a2;
int a, b;

bool query(int a, int b)
{
	printf("? %d %d\n", a, b); 
	fflush(stdout);
	int res; scanf("%d", &res);
	return res > 0;
}

void solve_digit(int pos)
{
	a1 = query(a ^ 1 << pos, b);
	a2 = query(a, b ^ 1 << pos);
	int mask = (a0 << 2) + (a1 << 1) + (a2 << 0);
	a += da[mask] << pos;
	b += db[mask] << pos;
	a0 = d0[mask];
}

int main()
{
	a0 = query(a, b);
	for (int i = 29; i >= 0; --i)
		solve_digit(i);
	printf("! %d %d\n", a, b);
	fflush(stdout);
	return 0;
}