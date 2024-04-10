#include <cstdio>
#include <algorithm>
const int N = 4e5;
int n, sum[N], min;

int check(int val, int &l, int &r)
{
	val += sum[0];
	int x, y, cur = 0, res = 0;
	for (int i = 0; i < n; ++i)
		if (sum[i] == val)
		{
			if (!cur++)
				x = i - 1;
			y = i;
			if (res < cur)
			{
				res = cur;
				l = x;
				r = y;
			}
		}
		else if (sum[i] < val)
			cur = 0;
	// printf("check %d %d %d\n", val, l, r);
	l = (l + min) % n + 1;
	r = (r + min) % n + 1;
	return res;
}

int main()
{
	scanf("%d ", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + (getchar() == '(' ? 1 : -1);
		if (sum[i] < sum[min])
		{
			min = i;
			cnt = 1;
		}
		else if (sum[i] == sum[min])
			++cnt;
	}
	if (sum[n] == 0)
	{
		std::rotate(sum, sum + min, sum + n);
		int l1 = 1, r1 = 1, res1 = check(2, l1, r1) + cnt;
		int l2 = 1, r2 = 1, res2 = check(1, l2, r2);
		if (res1 > res2)
			printf("%d\n%d %d\n", res1, l1, r1);
		else 
			printf("%d\n%d %d\n", res2, l2, r2);
	}
	else 
		printf("0\n1 1\n");
}