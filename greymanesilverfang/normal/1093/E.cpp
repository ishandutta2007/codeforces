#include <algorithm>
#include <iostream>
#include <vector>
const int N = 2e5+1;
int n, m, a[N], b[N], t[N], lo[N], hi[N], l[N], r[N];
std::vector<int> value[N], fen[N];

void prep(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
		value[i].push_back(y);
}

void add(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		auto it = std::lower_bound(value[i].begin(), value[i].end(), y);
		for (int j = it - value[i].begin() + 1; j <= value[i].size(); j += j & -j)
			++fen[i][j];
	}
}

void del(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		auto it = std::lower_bound(value[i].begin(), value[i].end(), y);
		for (int j = it - value[i].begin() + 1; j <= value[i].size(); j += j & -j)
			--fen[i][j];
	}
}

int get(int x, int y)
{
	// std::cout << "get " << x << ' ' << y << std::endl;
	int res = 0;
	for (int i = x; i >= 1; i -= i & -i)
	{
		auto it = std::upper_bound(value[i].begin(), value[i].end(), y);
		for (int j = it - value[i].begin(); j >= 1; j -= j & -j)
			res += fen[i][j];
	}
	// std::cout << "res = " << res << std::endl;
	return res;
}

int main()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		a[i] = b[a[i]];
	}
	for (int i = 1; i <= n; ++i)
	{
		b[i] = a[i];
		prep(i, b[i]);
	}
	for (int i = 1; i <= m; ++i)
	{
		std::cin >> t[i];
		if (t[i] == 1)
			std::cin >> lo[i] >> hi[i] >> l[i] >> r[i];
		else 
		{
			std::cin >> l[i] >> r[i];
			std::swap(b[l[i]], b[r[i]]);
			prep(l[i], b[l[i]]);
			prep(r[i], b[r[i]]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		std::sort(value[i].begin(), value[i].end());
		value[i].resize(std::unique(value[i].begin(), value[i].end()) - value[i].begin());
		fen[i].resize(value[i].size() + 1);
	}
	for (int i = 1; i <= n; ++i)
		add(i, a[i]);
	for (int i = 1; i <= m; ++i)
		if (t[i] == 1)
			std::cout << get(l[i] - 1, lo[i] - 1)
			           - get(l[i] - 1, hi[i])
			           - get(r[i], lo[i] - 1)
			           + get(r[i], hi[i]) << std::endl;
		else 
		{
			del(l[i], a[l[i]]);
			del(r[i], a[r[i]]);
			std::swap(a[l[i]], a[r[i]]);
			add(l[i], a[l[i]]);
			add(r[i], a[r[i]]);
		}
	return 0;
}