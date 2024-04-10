#include <iomanip>
#include <iostream>
const int N = 1e5+1;
int deg[N];

int main()
{
	int n, s; std::cin >> n >> s;
	for (int i = 1; i < n; ++i)
	{
		int a, b; std::cin >> a >> b;
		++deg[a];
		++deg[b];
	}
	int leaf = 0;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 1)
			++leaf;
	std::cout << std::setprecision(9) << (double) s * 2 / leaf;
	return 0;
}