#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<map>
#include<fstream>
#include<set>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++)
	{
		int h, w;
		cin >> h >> w;
		vector<vector<int>>v(h, vector<int>(w, 0));
		v[0][0] = 1;
		v[0][w - 1] = 1;
		v[h - 1][w - 1] = 1;
		v[h - 1][0] = 1;
		for (int i = 0; i < w - 2; i++)
		{
			if (i % 2 == 0)
			{
				v[0][i] = 1;
				v[h - 1][i] = 1;
			}
		}
		for (int i = 0; i < h - 2; i++)
		{
			if (i % 2 == 0)
			{
				v[i][0] = 1;
				v[i][w - 1] = 1;
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cout << v[i][j];
			cout << endl;
		}
		cout << endl;
	}
}