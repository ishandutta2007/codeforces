#include <cstdio>
#include <vector>
#include <algorithm>

int find_end(const std::vector<int> &v, int pos)
{
	while (++pos < v.size())
		if (v[pos] - 1 != v[pos - 1])
			break;
	return pos;
}

int find_prv(const std::vector<int> &v, int pos)
{
	int res = -1;
	for (int i = 0; i < v.size(); ++i)
		if (v[pos] - 1 == v[i])
		{
			res = i + 1;
			break;
		}
	return res;
}

std::vector<int> modify(const std::vector<int> &v)
{
	std::vector<int> res;
	for (int i = 0; i < v.size(); ++i)
	{
		int j = find_end(v, i);
		int k = find_prv(v, i);
		if (i < k)
		{
			if (i != 0)
				res.push_back(i);
			res.push_back(j - i);
			res.push_back(k - j);
			if (k != v.size())
				res.push_back(v.size() - k);
			break;
		}
	}
	return res;
}

int main()
{
	int n; scanf("%d", &n);
	std::vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		int x; scanf("%d", &x);
		v.push_back(x);
	}
	std::vector<std::vector<int>> res;
	while (true)
	{
		std::vector<int> u = modify(v);
		if (u.empty())
			break;
		int cur = 0;
		std::vector<int> tmp(n);
		for (int x : u)
		{
			std::copy(v.begin() + cur, v.begin() + cur + x, tmp.end() - cur - x);
			cur += x;
		}
		std::swap(v, tmp);
		res.push_back(u);
	}
	printf("%d\n", res.size());
	for (std::vector<int> v : res)
	{
		printf("%d ", v.size());
		for (int x : v)
			printf("%d ", x);
		printf("\n");
	}
}