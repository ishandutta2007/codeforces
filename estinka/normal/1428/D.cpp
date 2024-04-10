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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	set<int> use2, use3; // tie ktore mozu vyuzit 3 - este
	// nemaju vo svojom stlpci dva predmety a tie ktore mozu vyuzit 2
	// - este nemaju vo svojom riadku 2 predmety
	vector<pair<int, int> > o;
	int last2 = n, last3 = n;
	vector<int> one;
	for (int i = n - 1; i >= 0; i--)
	{
		// mozme davat prekazku do riadku n - i
		if (a[i] == 1)
		{
			o.push_back({ i + 1, i + 1 });
			one.push_back(i);
		}
		else if (a[i] == 2)
		{
			if (one.empty())
			{
				cout << "-1\n";
				return 0;
			}
			int s = one.back();
			one.pop_back();
			o.push_back({ s + 1, i + 1 });
			last2 = i;
		}
		else if (a[i] == 3)
		{
			if (last2 == n && one.empty())
			{
				cout << "-1\n";
				return 0;
			}
			if (last3 == n && last2 == n)
			{
				last2 = one.back();
				one.pop_back();
			}
			int s = (last3 == n ? last2 : last3);
			o.push_back({ i + 1, i + 1 });
			o.push_back({ i + 1, s + 1 });
			last3 = i;
		}
	}
	cout << o.size() << "\n";
	for (int i = 0; i < o.size(); i++)
	{
		cout << o[i].first << " " << o[i].second << "\n";
	}
	return 0;
}