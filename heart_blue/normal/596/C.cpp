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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
map<int, map<int, int>> ms;
vector<pair<int,int>> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		ms[y - x][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int o;
		cin >> o;
		if (ms[o].empty())
		{
			cout << "NO" << endl;
			return 0;
		}
		int x = ms[o].begin()->first;
		ms[o].erase(x);
		ans.push_back({ x,o + x });
	}
	for (int i = 1; i < n; i++)
	{
		if (ans[i - 1].first >= ans[i].first && ans[i - 1].second >= ans[i].second)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	puts("YES");
	for (auto &p : ans) printf("%d %d\n", p.first, p.second);
	return 0;
}