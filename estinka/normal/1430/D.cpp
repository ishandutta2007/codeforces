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
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || s[i] != s[i - 1])
			{
				v.push_back(0);
			}
			v.back()++;
		}
		reverse(v.begin(), v.end());
		int in = v.size() - 1;
		int k = 0;
		while (true)
		{
			if (v.empty())
			{
				break;
			}
			k++;
			while (in > 0 && (in == v.size() || v[in] == 1))
			{
				in--;
			}
			if (in < 0 || in == v.size() || v[in] == 1)
			{
				if (!v.empty())
				{
					v.pop_back();
				}
			}
			else
			{
				v[in]--;
			}
			if (!v.empty())
			{
				v.pop_back();
			}
		}
		cout << k << "\n";
	}
	return 0;
}