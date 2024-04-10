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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[20][20];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> vp;
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			for (int j = 0; j < m; j++)
			{
				if (str[i][j] == 'R')
					vp.emplace_back(i, j);
			}
		}
		sort(vp.begin(), vp.end());
		auto [x, y] = vp.front();
		int flag = 1;
		for (auto [a, b] : vp)
		{
			if (a < x || b < y)
			{
				flag = 0;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}