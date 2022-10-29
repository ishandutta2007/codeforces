#include <cstdio>
#include <algorithm>
int r, c;
char a[70][70];
int sumr[70][70], sumc[70][70];

bool corner(int x, int y)
{
	return (x == 1 || x == r) && (y == 1 || y == c);
}

bool edge(int x, int y)
{
	return (x == 1 || x == r) || (y == 1 || y == c);
}

int solve()
{
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i)
		scanf("%s", &a[i][1]);
	int sum = 0, res = 69;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
		{
			sumr[i][j] = sumr[i][j - 1];
			sumc[i][j] = sumc[i - 1][j];
			if (a[i][j] == 'A')
			{
				++sum; 
				++sumr[i][j];
				++sumc[i][j];
				bool slice = sumr[i][j] == c || sumc[i][j] == r;
				if (corner(i, j) && slice)
					res = std::min(res, 1);
				if (corner(i, j) || slice)
					res = std::min(res, 2);
				if (edge(i, j))
					res = std::min(res, 3);
				res = std::min(res, 4);
			}
		}
	if (sum == 0)
		return -1;
	if (sum == r * c)
		return 0;
	return res;
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int res = solve();
		if (res != -1)
			printf("%d\n", res);
		else 
			printf("MORTAL\n");
	}
}