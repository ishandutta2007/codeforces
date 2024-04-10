#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, ans, sum;

int main()
{
	scanf("%d%d", &n, &k);
	k = 240 - k;
	for (int i = 1; ; i ++)
	{
		sum += i * 5;
		if (sum > k)
		{
			ans = i - 1;
			break ;
		}
	}
	printf("%d\n", min(ans, n));
	return 0;
}