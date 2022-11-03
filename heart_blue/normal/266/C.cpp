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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[N][N];
int row[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		row[x]++;
	}
	vector<tuple<int, int, int>> vp;
	for (int i = n; i > 1; i--)
	{
		int k = i;
		for (int j = i; j >= 1; j--)
		{
			if (row[k] < row[j]) k = j;
		}
		if (k != i)
		{
			vp.emplace_back(1, k, i);
			swap(row[k], row[i]);
			for (int j = 1; j <= n; j++)
			{
				swap(a[i][j], a[k][j]);
			}
		}
	}
	int cur = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i][j]) flag[j] = 1;
		}
		for (int j = n; j >= i; j--)
		{
			if (a[i][j])
			{
				while (flag[cur]) cur++;
				flag[cur] = 1;
				int o = cur;
				for (int k = 1; k <= n; k++)
				{
					swap(a[k][o], a[k][j]);
				}
				vp.emplace_back(2, o, j);

			}
		}
	}
	printf("%d\n", vp.size());
	for (auto& p : vp)
	{
		int o, x, y;
		tie(o, x, y) = p;
		printf("%d %d %d\n", o, x, y);
	}
	return 0;
}