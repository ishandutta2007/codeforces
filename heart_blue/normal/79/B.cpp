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
const int N = 1e5 + 10;
map<pair<int, int>, int> mp;
int sum[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= n; i++) sum[i] = m;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		mp[{x, y}] = 1;
		sum[x]--;
		v[x].push_back(y);
	}
	vector<string> vs = { "Grapes", "Carrots","Kiwis"};
	for (int i = 1; i <= n; i++)
	{
		sum[i] = (sum[i - 1] + sum[i]) % 3;
		if (!v[i].empty()) sort(v[i].begin(), v[i].end());
	}
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (mp.count({ x,y })) puts("Waste");
		else
		{
			int waste = lower_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
			puts(vs[(sum[x - 1] + y - waste)%3].c_str());
		}
	}
	return 0;
}