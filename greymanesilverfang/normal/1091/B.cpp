#include <algorithm>
#include <iostream>
#include <map>
const int N = 1001;
int x[N], y[N], a[N], b[N];
std::map<std::pair<int,int>,int> cnt;

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i] >> b[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			++cnt[std::make_pair(x[i] + a[j], y[i] + b[j])];
	for (auto p : cnt)
		if (p.second == n)
		{
			std::cout << p.first.first << ' ' << p.first.second;
			break;
		}
	return 0;
}