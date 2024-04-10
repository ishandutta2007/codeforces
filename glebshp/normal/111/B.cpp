#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433832795

const int size = 200 * 1000;

int last[size];

int ans(int x, int y, int num)
{
	int p = 1, a = 0;
	while (p * p <= x)
	{
		if ((x % p) == 0)
		{
			if (p * p == x)
				a += (last[p] < num - y);
			else
				a += (last[p] < num - y) + (last[x / p] < num - y);
			last[p] = num;
			last[x / p] = num;
		}
		p++;
	}
	return a;
}

int main() {
	int i, n, x, y;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (i = 0; i <= size; i++)
		last[i] = -1;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << ans(x, y, i) << endl;
	}

	return 0;
}