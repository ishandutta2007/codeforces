#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

ll gcd(ll a, ll b)
{
	a = abs(a);
	b = abs(b);
	if (b > a) swap(a, b);
	while (b)
	{
		ll c = b;
		b = a % b;
		a = c;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll k;
		cin >> n >> k;
		vector<ll> x(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		ll g = x[1] - x[0];
		for (int i = 2; i < n; i++) g = gcd(g, x[i] - x[0]);
		if (abs(k - x[0]) % g == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}