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

ll divup(ll a, ll b)
{
	if (a % b == 0)
	{
		return a / b;
	}
	return a / b + 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n >> x;
		if (n <= 2)
		{
			cout << 1 << "\n";
			continue;
		}
		n -= 2;
		cout << divup(n, x) + 1 << "\n";
	}
	return 0;
}