/*input
4
2 0
0 2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
struct point
{
	ll x, y;
	point()
	{
		x = y = 0;
	}
	point(ll a, ll b)
	{
		x = a;
		y = b;
	}
};
point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	point dx1, dx2;
	cin >> dx1.x >> dx1.y >> dx2.x >> dx2.y;
	if (cross(dx1, dx2) == 0)
	{
		cout << "NO\n";
		return 0;
	}
	set<pair<int, int>>ans;
	point X[4] = {point(), dx1, dx1 + dx2, dx2};
	for (ll x = -1e6; x <= 1e6; x++)
	{
		ld lo = 1e90;
		ld hi = -1e90;
		for (int i = 0; i < 4; i++)
		{
			int j = (i + 1) % 4;
			point a = X[i];
			point b = X[j];
			if (a.x == b.x)
			{
				if (x == a.x)
				{
					lo = min(lo, ld(a.y));
					lo = min(lo, ld(b.y));
					hi = max(hi, ld(a.y));
					hi = max(hi, ld(b.y));
				}
			}
			else
			{
				if (min(a.x, b.x) <= x && x <= max(a.x, b.x))
				{
					ld y = a.y + ld(b.y - a.y) * ld(x - a.x) / ld(b.x - a.x);
					lo = min(lo, y);
					hi = max(hi, y);
				}
			}
		}
		for (ll y = round(lo - 2); y <= hi + 1e-8; y++)
		{
			if (y >= lo - 1e-8)
			{
				if (ans.count({x - dx1.x, y - dx1.y}) || ans.count({x + dx1.x, y + dx1.y}))
					continue;
				if (ans.count({x - dx2.x, y - dx2.y}) || ans.count({x + dx2.x, y + dx2.y}))
					continue;
				if (ans.count({x - dx1.x - dx2.x, y - dx1.y - dx2.y}))
					continue;
				if (ans.count({x - dx1.x + dx2.x, y - dx1.y + dx2.y}))
					continue;
				if (ans.count({x + dx1.x - dx2.x, y + dx1.y - dx2.y}))
					continue;
				if (ans.count({x + dx1.x + dx2.x, y + dx1.y + dx2.y}))
					continue;
				ans.insert({x, y});
				if (ans.size() > n)
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	if (ans.size() == n)
	{
		cout << "YES\n";
		for (auto i : ans)
			cout << i.first << " " << i.second << "\n";
	}
	else
	{
		cout << "NO\n";
	}
}