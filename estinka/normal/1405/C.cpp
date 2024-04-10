// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
typedef long long ll;
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<vector<int> > v(k);
		for (int i = 0; i < n; i++)
		{
			if (s[i] != '?')
			{
				v[i % k].push_back(s[i] - '0');
			}
		}
		bool good = true;
		for (int i = 0; i < k; i++)
		{
			for (int j : v[i])
			{
				if (j != v[i][0])
				{
					good = false;
					break;
				}
			}
			if (!v[i].empty())
			{
				for (int j = i; j < n; j += k)
				{
					s[j] = v[i][0] + '0';
				}
			}
		}
		int z = 0, o = 0;
		for (int i = 0; i < k; i++)
		{
			if (s[i] != '?')
			{
				if (s[i] == '0')
				{
					z++;
				}
				else
				{
					o++;
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (s[i] == '?')
			{
				if (z < o)
				{
					s[i] = '0';
					z++;
				}
				else
				{
					s[i] = '1';
					o++;
				}
				for (int j = i; j < n; j += k)
				{
					s[j] = s[i];
				}
			}
		}
		z = 0, o = 0;
		// Ak niekedy pocet 0 a 1 vyjde prec z rovnovahy o viac ako 1
		for (int i = 0; i < k; i++)
		{
			if (s[i] == '0')
			{
				z++;
			}
			if (s[i] == '1')
			{
				o++;
			}
		}
		if (z != o)
		{
			good = false;
		}
		for (int i = 0; i + k < n; i++)
		{
			if (s[i + k] == '0')
			{
				z++;
			}
			if (s[i + k] == '1')
			{
				o++;
			}
			if (s[i] == '0')
			{
				z--;
			}
			if (s[i] == '1')
			{
				o--;
			}
			if (z != o)
			{
				good = false;
				break;
			}
		}
		//cout << s << "\n";
		if (good)
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