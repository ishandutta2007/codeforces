#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

const double pi = 3.14159265358979323846;

long long maxd = 1, bound = 1e5;

bool check(const vector<long long> &a, long long k, long long n)
{
	long long sum = 0;

	if (n < maxd)
		return true;

	for (auto it : a)
	{
		auto t = n - (it % n);

		if (t != n)
			sum += t;
	}

	if (sum <= k)
	{
		maxd = n;

		return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	long long k;

	cin >> n >> k;

	vector<long long> a(n);

	for (auto &it : a)
		cin >> it;
	
	for (int i = 2; i <= bound; i++)
		check(a, k, i);

	unordered_set<long long> edges;

	for (auto it : a)
		for (int i = 1; (i * bound) <= it; i++)
		{
			edges.insert(it / i);
			edges.insert((it + i - 1) / i);
		}

	for (auto it : edges)
		check(a, k, it);

	long long r = 1e12;

	for (auto it : edges)
		if (maxd < it)
			r = min(r, it);

	long long l = maxd;

	while (l + 1 < r)
	{
		auto t = (l + r) / 2;

		(check(a, k, t) ? l : r) = t;
	}

	cout << l << endl;

	return 0;
}