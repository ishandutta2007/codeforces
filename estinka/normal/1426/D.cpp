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
	int n;
	cin >> n;
	vector<ll> a(n);
	set<ll> s;
	s.insert(0);
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if (s.count(sum))
		{
			// musime pred prvok a[i]
			// vsunut nejaky novy prvok
			ans++;
			s.clear();
			s.insert(sum - a[i]);
		}
		s.insert(sum);
	}
	cout << ans << "\n";
	return 0;
}