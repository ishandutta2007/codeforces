#include <algorithm>
#include <iostream>
const int N = 3e5+1;
int a[N];

int sqr(int x)
{
	return x * x;
}

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	long long res = 0;
	for (int i = 1; i <= n - i; ++i)
		res += sqr(a[i] + a[n - i + 1]);
	std::cout << res;
	return 0;
}