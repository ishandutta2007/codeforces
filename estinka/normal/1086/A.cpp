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
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxi = 1079;
vector<vector<int> > f(maxi, vector<int>(maxi, 0));
void connect(int x1, int y1, int x2, int y2, vector<pair<int, int> > &myans)
{
	if (!f[x1][y1])
	{
		f[x1][y1] = 1;
		myans.push_back({ x1, y1 });
	}
	for (; x1 < x2;)
	{
		x1++;
		if (!f[x1][y1])
		{
			f[x1][y1] = 1;
			myans.push_back({ x1, y1 });
		}
	}
	for (; x1 > x2;)
	{
		x1--;
		if (!f[x1][y1])
		{
			f[x1][y1] = 1;
			myans.push_back({ x1, y1 });
		}
	}
	for (; y1 < y2;)
	{
		y1++;
		if (!f[x1][y1])
		{
			f[x1][y1] = 1;
			myans.push_back({ x1, y1 });
		}
	}
	for (; y1 > y2;)
	{
		y1--;
		if (!f[x1][y1])
		{
			f[x1][y1] = 1;
			myans.push_back({ x1, y1 });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// Najprv vycistime cestu medzi lubovolnymi dvoma
	// Potom sa pozrieme
	int x[3], y[3];
	for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

	vector<pair<int, int> > bestans(1, { -1, -1 });
	vector<int>p;
	for (int i = 0; i < 3; i++) p.push_back(i);
	do
	{
		vector<pair<int, int> > myans;
		connect(x[p[0]], y[p[0]], x[p[1]], y[p[1]], myans);
		pair<int, int> cl = myans[0];
		for (pair<int, int> i : myans)
			if (abs(i.first - x[p[2]]) + abs(i.second - y[p[2]]) < abs(cl.first - x[p[2]]) + abs(cl.second - y[p[2]]))
				cl = i;
		connect(cl.first, cl.second, x[p[2]], y[p[2]], myans);
		if (bestans.back().first == -1 || bestans.size() > myans.size()) bestans = myans;
		for (pair<int, int> i : myans) f[i.first][i.second] = 0;
	} while (next_permutation(p.begin(), p.end()));
	cout << bestans.size() << "\n";
	for (int i = 0; i < bestans.size(); i++) cout << bestans[i].first << " " << bestans[i].second << "\n";
	return 0;
}