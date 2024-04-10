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
#include <chrono>
//#define DEBUG
//#define RANDOM
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll>a(3), b(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	vector<ll> ca = a;
	vector<ll> cb = b;
	ll win = 0;
	for (int i = 0; i < 3; i++)
	{
		// kolkokrat moze i-ty znak vyhrat?
		ll can = min(b[(i + 1) % 3], a[i]);
		win += can;
		b[(i + 1) % 3] -= can;
		a[i] -= can;
	}
	// uz vieme kolko krat vyhra.
	// Nevyhra vtedy, ked ona ukaze i
	// a bob neukaze i
	a = ca;
	b = cb;
	ll mini = 0;
	for (int i = 0; i < 3; i++)
	{
		if (a[i] + b[(i + 1) % 3] >= n)
		{
			mini += a[i] + b[(i + 1) % 3] - n;
		}
	}
	cout << mini << " " << win << "\n";
	return 0;
}