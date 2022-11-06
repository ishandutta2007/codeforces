#include <cstdio>
#include <algorithm>
using namespace std;

int n, X[5], Y[5];

inline void Get(int x_1, int y_1, int x_2, int y_2, int op, int cur)
{
	if (cur == 4)
	{
		X[1 + op * 2] = x_1, Y[1 + op * 2] = y_1;
		X[2 + op * 2] = x_2, Y[2 + op * 2] = y_2;
		return ;
	}
	if (cur == 0)
	{
		int l = x_1, r = x_2;
		while (l < r)
		{
			int mid = l + r >> 1, res;
			printf("? %d %d %d %d\n", x_1, y_1, mid, y_2);
			fflush(stdout);
			scanf("%d", &res);
			if (op && x_1 <= X[1] && y_1 <= Y[1] && mid >= X[2] && y_2 >= Y[2])
				res --;
			if (res) r = mid;
				else l = mid + 1;
		}
		Get(x_1, y_1, l, y_2, op, cur + 1);
	}
	else if (cur == 1)
	{
		int l = x_1, r = x_2;
		while (l < r)
		{
			int mid = l + r + 1 >> 1, res;
			printf("? %d %d %d %d\n", mid, y_1, x_2, y_2);
			fflush(stdout);
			scanf("%d", &res);
			if (op && mid <= X[1] && y_1 <= Y[1] && x_2 >= X[2] && y_2 >= Y[2])
				res --;
			if (res) l = mid;
				else r = mid - 1;
		}
		Get(l, y_1, x_2, y_2, op, cur + 1);		
	}
	else if (cur == 2)
	{
		int l = y_1, r = y_2;
		while (l < r)
		{
			int mid = l + r >> 1, res;
			printf("? %d %d %d %d\n", x_1, y_1, x_2, mid);
			fflush(stdout);
			scanf("%d", &res);
			if (op && x_1 <= X[1] && y_1 <= Y[1] && x_2 >= X[2] && mid >= Y[2])
				res --;
			if (res) r = mid;
				else l = mid + 1;
		}
		Get(x_1, y_1, x_2, l, op, cur + 1);
	}
	else if (cur == 3)
	{
		int l = y_1, r = y_2;
		while (l < r)
		{
			int mid = l + r + 1 >> 1, res;
			printf("? %d %d %d %d\n", x_1, mid, x_2, y_2);
			fflush(stdout);
			scanf("%d", &res);
			if (op && x_1 <= X[1] && mid <= Y[1] && x_2 >= X[2] && y_2 >= Y[2])
				res --;
			if (res) l = mid;
				else r = mid - 1;
		}
		Get(x_1, l, x_2, y_2, op, cur + 1);
	}
}

int main()
{
	scanf("%d", &n);
	Get(1, 1, n, n, 0, 0);
	Get(1, 1, n, n, 1, 0);
	printf("! %d %d %d %d %d %d %d %d\n", X[1], Y[1], X[2], Y[2], X[3], Y[3], X[4], Y[4]);
	return 0;
}