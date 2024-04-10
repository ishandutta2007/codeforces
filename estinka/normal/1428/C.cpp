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
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			res.push_back(s[i]);
			if (res.size() > 1 && res.back() == 'B')
			{
				res.pop_back();
				res.pop_back();
			}
		}
		cout << res.size() << "\n";
	}
	return 0;
}