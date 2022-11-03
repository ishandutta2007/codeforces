#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 60;
int a[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, x;
	cin >> n >> k >> x;
	MEM(a, 0);
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		int y;
		cin >> y;
		a[o][y]++;
	}
	while (k--)
	{
		o ^= 1;
		MEM(a[o], 0);
		int t = 0;
		for (int i = 0; i < N; i++)
		{
			if (a[o ^ 1][i] == 0) continue;
			int rest = 0;
			if (a[o ^ 1][i] & 1)
			{
				rest = a[o ^ 1][i] / 2;
				if (t) rest++;
				t ^= 1;
			}
			else
			{
				rest = a[o ^ 1][i] / 2;
			}
			a[o][i] += rest;
			a[o][i^x] += a[o ^ 1][i] - rest;
		}
	}
	int minv = INF, maxv = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[o][i])
		{
			minv = min(i, minv);
			maxv = max(i, maxv);
		}
	}
	cout << maxv << ' ' << minv << endl;
	return 0;
}