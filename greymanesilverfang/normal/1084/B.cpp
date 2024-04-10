// #binary_search

#include <iostream>
const int N = 1001, INF = 1e9+7;
int v[N];

int main()
{
	int n; std::cin >> n;
	long long s; std::cin >> s;
	for (int i = 1; i <= n; ++i)
		std::cin >> v[i];
	int min = INF;
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		min = std::min(min, v[i]);
		sum += v[i];
	}
	if (sum < s)
		std::cout << -1;
	else 
		std::cout << std::min((long long) min, (sum - s) / n);
	return 0;
}