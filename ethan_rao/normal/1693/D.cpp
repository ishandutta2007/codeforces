#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
#define all(x) (x).begin(), (x).end()
struct custom_hash // this is from https://codeforces.com/blog/entry/62393
{
	static uint64_t splitmix64(uint64_t x)
	{
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
unordered_map<ll, int, custom_hash> mp;
const int N = 2e5 + 5;
int a[N], f[N], n;
int dfs(int x, int l, int r)
{
	if (x == n + 1)
		return x;
	auto &it = mp[((ll)l * N + r) * N + x];
	if (it)
	{
		return it;
	}
	if (l < a[x] && a[x] < r)
	{
		if (x == n)
			return n + 1;
		if (a[x + 1] > a[x])
			l = a[x];
		else
			r = a[x];
		return it = dfs(x + 1, l, r);
	}
	else if (a[x] < r)
	{
		return it = dfs(x + 1, l, a[x]);
	}
	else if (a[x] > l)
	{
		return it = dfs(x + 1, a[x], r);
	}
	return x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
		f[i] = dfs(i, 0, n + 1) - i;
	// for (i = 1; i <= n; i++)
	//	cerr << f[i] << " \n"[i == n];
	cout << accumulate(f + 1, f + n + 1, 0ll) << endl;
}