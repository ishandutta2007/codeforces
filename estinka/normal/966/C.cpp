#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

void bad()
{
	cout << "No\n";
	exit(0);
}
const ll logn = 60;
int highest_bit(ll x)
{
	for (ll i = logn; i >= 0; i--) if (x & (1ll << i)) return i;
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<ll> > b(logn);
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		b[highest_bit(a)].push_back(a);
	}
	for (int i = 0; i < logn; i++) sort(b[i].begin(), b[i].end(), greater<ll>());
	vector<ll> v;
	ll last = 0;
	for (int i = 0; i < n; i++)
	{
		for (ll j = 0; j < logn; j++)
		{
			if (!((1ll << j) & last) && !b[j].empty())
			{
				v.push_back(b[j].back());
				last ^= b[j].back();
				b[j].pop_back();
				break;
			}
		}
		if (v.size() != i + 1) bad();
	}
	cout << "Yes\n";
	for (int i = 0; i < n; i++) cout << v[i] << " ";
	cout << "\n";
	return 0;
}