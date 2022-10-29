#include <algorithm>
#include <iostream>
#include <vector>
#define iter std::vector<int>::iterator
const int N = 5e5+1;
int n, a[N];
long long total;

int val(int x)
{
	return x * 2 + total % 2;
}

bool check_min(int x)
{
	std::vector<int> v;
	v.push_back(x);
	for (int i = 1; i <= n; ++i)
		v.push_back(a[i]);
	std::sort(v.begin(), v.end());
	long long sum = 0, lim = 0;
	iter it = std::upper_bound(v.begin(), v.end(), x);
	for (iter it1 = v.begin(), it2 = v.end() - 1; it2 >= it; --it2)
	{
		sum += *it2;
		int k = v.end() - it2;
		while (it1 < it2 && *it1 < k)
			lim += *it1++;
		if (it1 > it2)
			lim -= *it1--;
		if (lim + 1LL * k * ((it2 - it1) + k - 1) < sum)
			return false;
	}
	return true;
}

int BS_min()
{
	int l = 0, r = n / 2;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check_min(val(mid)))
			r = mid - 1;
		else 
			l = mid + 1;
	}
	return l;
}

bool check_max(int x)
{
	std::vector<int> v;
	v.push_back(x);
	for (int i = 1; i <= n; ++i)
		v.push_back(a[i]);
	std::sort(v.begin(), v.end());
	long long sum = total, lim = 0;
	iter it = std::lower_bound(v.begin(), v.end(), x);
	for (iter it1 = v.begin(); it1 < it; ++it1)
		sum -= *it1;
	for (iter it1 = v.begin(), it2 = it; it2 >= v.begin(); --it2)
	{
		sum += *it2;
		int k = v.end() - it2;
		while (it1 < it2 && *it1 < k)
			lim += *it1++;
		if (it1 > it2)
			lim -= *it1--;
		if (lim + 1LL * k * ((it2 - it1) + k - 1) < sum)
			return false;
	}
	return true;
}

int BS_max()
{
	int l = 0, r = n / 2;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check_max(val(mid)))
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return r;
}

int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= n; ++i)
		total += a[i];
	int l = BS_min(), 
	    r = BS_max();
	if (r < l)
		std::cout << -1;
	else for (int i = l; i <= r; ++i)
		std::cout << val(i) << ' ';
	return 0;
}