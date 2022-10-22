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
	// vypocitame si, ktore mohli byt
	const int maxi = 1001;
	vector<vector<int> > answ(maxi);
	for (int i = 0; i * 7 < maxi; i++)
	{
		for (int j = 0; i * 7 + j * 5 < maxi; j++)
		{
			for (int k = 0; i * 7 + j * 5 + k * 3 < maxi; k++)
			{
				if (answ[i * 7 + j * 5 + k * 3].empty())
				{
					answ[i * 7 + j * 5 + k * 3] = { k, j, i };
				}
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (answ[n].empty())
		{
			cout << "-1\n";
		}
		else
		{
			cout << answ[n][0] << " " << answ[n][1] << " " << answ[n][2] << "\n";
		}
	}
	return 0;
}