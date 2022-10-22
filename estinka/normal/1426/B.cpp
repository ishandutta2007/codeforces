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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		bool dia = false;
		bool sym = false;
		vector<vector<int> > d(n, vector<int>(4));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> d[i][j];
			}
			if (d[i][1] == d[i][2])
			{
				dia = true;
			}
		}
		if (m & 1)
		{
			cout << "NO\n";
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (d[i][0] == d[j][0] && d[i][1] == d[j][2] && d[i][2] == d[j][1] && d[i][3] == d[j][3])
				{
					sym = true;
					break;
				}
			}
			if (sym)
			{
				break;
			}
		}
		if (m == 2 && dia)
		{
			cout << "YES\n";
		}
		else if (dia && sym)
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