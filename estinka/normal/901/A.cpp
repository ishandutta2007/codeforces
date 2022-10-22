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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h;
	cin >> h; h++;
	vector<int> a(h);
	for (int i = 0; i < h; i++)
	{
		cin >> a[i];
	}
	int in = -1;
	for (int i = 0; i < h - 1; i++)
	{
		if (min(a[i], a[i + 1]) > 1)
		{
			in = i;
			break;
		}
	}
	if (in == -1)
	{
		cout << "perfect\n";
	}
	else
	{
		cout << "ambiguous\n";
		int n = 0;
		vector<vector<int> > lvl(h);
		vector<int> l;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < a[i]; j++)
			{
				lvl[i].push_back(n++);
				l.push_back(i);
			}
		vector<int> p1(n, -1), p2(n, -1);
		for (int i = 1; i < n; i++)
		{
			if (l[i] != in + 1 || l[i - 1] < in + 1) p1[i] = p2[i] = lvl[l[i] - 1].back();
			else
			{
				p1[i] = lvl[in][lvl[in].size() - 2];
				p2[i] = lvl[in].back();
			}
		}
		for (int i = 0; i < n; i++) cout << p1[i] + 1 << " ";
		cout << "\n";
		for (int i = 0; i < n; i++) cout << p2[i] + 1 << " ";
		cout << "\n";
	}
	return 0;
}