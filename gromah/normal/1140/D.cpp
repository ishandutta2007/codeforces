#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 2; i < n; i ++)
		ans += i * (i + 1);
	printf("%d\n", ans);
	return 0;
}