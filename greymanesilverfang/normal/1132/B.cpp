#include <algorithm>
#include <iostream>
const int N = 300003;
int a[N], q[N];

int main()
{
	long long sum = 0;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		sum += a[i];
	}
	std::sort(a, a + n);
	int m; std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		std::cin >> q[i];
		std::cout << sum - a[n - q[i]] << '\n';
	}
	return 0;
}