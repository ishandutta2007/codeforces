#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
const int N = 200002; 
const long long INF = 2e12;
long long n, k, a[N], b[N], tmp[N], time[N], global_time, mark[N];
std::vector<int> vec[N];
struct my_compare {
	bool operator()(int l, int r) {
		if (time[l] != time[r])
			return time[l] < time[r];
		return l < r;
	}
};

inline void add(long long time, int index)
{
	if (k <= time)
		return;
	if (mark[time] < global_time)
	{
		mark[time] = global_time;
		vec[time].clear();
	}
	vec[time].push_back(index);
}

bool check(long long p) 
{
	++global_time;
	for (int i = 1; i <= n; ++i)
	{
		tmp[i] = a[i];
		time[i] = tmp[i] / b[i] + 1;
		add(time[i], i);
	}
	long long count = 0;
	for (int i = 1; i <= k - 1; ++i)
	{
		if (mark[i] < global_time)
			continue;
		for (int x : vec[i])
		{
			long long diff = (b[x] * i - tmp[x] - 1) / p + 1;
			tmp[x] += diff * p;
			time[x] = tmp[x] / b[x] + 1;
			add(time[x], x);
			count += diff;
		}
		if (count > i)
			return false;
	}
	return true;
}

int main()
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> b[i];
	bool naive = true;
	for (int i = 1; i <= n; ++i)
		if (a[i] / b[i] < k - 1)
			naive = false;
	if (naive)
	{
		std::cout << 0;
		return 0;
	}
	long long l = 1, r = INF;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (check(mid))
			r = mid - 1;
		else 
			l = mid + 1;
	}
	if (INF < l)
	{
		std::cout << -1;
		return 0;
	}
	std::cout << l;
	return 0;
}