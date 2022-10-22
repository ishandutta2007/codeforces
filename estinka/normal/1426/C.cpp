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
		ll n;
		cin >> n;
		// najprv pocas prvych niekolko
		// krokov zvysime prvy prvok
		// a potom ho duplikujeme
		// neoplati sa nam to rovit viac ako sqrt(n) krat
		ll ans = n - 1;
		ll a = max((int)sqrt((ld)n) - 10, 0);
		for (ll i=a;i<=a+20;i++)
		{
			ans = min(ans, i + divup(n, i + 1) - 1);
		}
		cout << ans << "\n";
	}
	return 0;
}