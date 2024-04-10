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
const int N = 2e5 + 10;
vector<pair<int, int>> v[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, -1);
	int n;
	cin >> n;
	int cur = 0;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y, i);
		v[y].emplace_back(x, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() > 2)
		{
			for (int j = 0; j < 3; j++)
			{
				ans[v[i][j].second] = cur++;
			}
			break;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (ans[i] == -1) ans[i] = cur++;
		printf("%d\n", ans[i]);
	}
	return 0;
}