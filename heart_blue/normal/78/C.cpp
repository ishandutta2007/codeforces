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
vector<int> v;
map<int, int> mc;
int n, m, k;
int dfs(int x)
{
	if (mc.count(x)) return mc[x];
	int& ret = mc[x];
	for (auto& d : v)
	{
		if (d >= x) break;
		if (x % d) continue;
		if (d < k) continue;
		if (x / d % 2 == 0)
		{
			ret = 1;
			break;
		}
		if (dfs(d) == 0)
		{
			ret = 1;
			break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	if (n % 2 == 0)
	{
		puts("Marsel");
		return 0;
	}
	for (int i = 1; i * i <= m; i++)
	{
		if (m % i) continue;
		v.push_back(i);
		if (i * i != m) v.push_back(m / i);
	}
	sort(v.begin(), v.end());
	if (!dfs(m)) puts("Marsel");
	else puts("Timur");
	return 0;
}