#include <cstdio>
#include <algorithm>
#include <bitset>
#include <functional>
const int N = 25, A = 50000, MX = N*A;
int n, a[N*2];
std::bitset<MX*2+1> res[N*2][N];

int main()
{
	int n; scanf("%d", &n); n *= 2;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	std::nth_element(a, a, a + n);
	std::nth_element(a + 1, a + n - 1, a + n, std::greater<int>());
	res[0][0].set(MX);
	for (int i = 1; i < n - 1; ++i)
	{
		res[i][0] = res[i - 1][0] >> a[i];
		for (int j = 1; j <= n / 2 - 1; ++j)
			res[i][j] = res[i - 1][j - 1] << a[i] | res[i - 1][j] >> a[i];
	}
	int cur = n - 2, sz = n / 2 - 1;
	for (int i = MX; i <= 2 * MX; ++i)
		if (res[cur][sz][i])
		{
			for (int j = cur; sz > 0; --cur)
				if (res[cur - 1][sz - 1][i - a[cur]])
				{
					i -= a[cur]; 
					--sz;
					std::swap(a[cur], a[j--]);
				}
				else 
					i += a[cur];
			break;
		}
	std::sort(a, a + n / 2);
	std::sort(a + n / 2, a + n, std::greater<int>());
	for (int i = 0; i < n / 2; ++i)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = n / 2; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}