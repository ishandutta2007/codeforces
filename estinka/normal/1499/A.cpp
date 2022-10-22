#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
typedef long long ll;
using namespace std;

bool check(ll k1, ll k2, ll d)
{
	return min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2 >= d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		if (check(k1, k2, w) && check(n - k1, n - k2, b)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}