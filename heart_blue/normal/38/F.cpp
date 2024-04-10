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
const int N = 2e5 + 10;
set<int> v[N];
int val[N];
tuple<int, int, int> dp[N];
int flag[N];
map<string, int> mc;
int cur = 0;
vector<string> vs;
int getid(const string& str)
{
	if (!mc.count(str))
	{
		mc[str] = cur;
		int sum = 0;
		int maxv = 0;
		for (auto& c : str)
		{
			int x = c - 'a' + 1;
			sum += x;
			maxv = max(maxv, x);
		}
		val[cur] += sum * maxv;
		vs.push_back(str);
		cur++;
	}
	return mc[str];
}
tuple<int, int, int> dfs(int x)
{
	if (v[x].empty())
	{
		return { val[x],0,0 };
	}
	if (flag[x]) return dp[x];
	flag[x] = 1;
	int ret1 = 0, ret2 = 0, ret3 = 0;
	for (auto& y : v[x])
	{
		auto [sum1, sum2, o] = dfs(y);
		if (o == 0)
		{
			ret3 = 1;
			break;
		}
	}
	for (auto& y : v[x])
	{
		auto [sum1, sum2, o] = dfs(y);
		if (o == ret3) continue;
		if (ret1 < sum1) ret1 = sum1, ret2 = sum2;
		if (ret1 == sum1) ret2 = min(ret2, sum2);
	}
	return dp[x] = { ret2+val[x],ret1,ret3};
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	getid("");
	while (n--)
	{
		vector<int> key;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 1; i + j <= str.length(); j++)
			{
				key.push_back(getid(str.substr(i, j)));
			}
			v[0].insert(getid(str.substr(i, 1)));
		}
		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 2; i + j <= str.length(); j++)
			{
				int z = getid(str.substr(i, j));
				int x = getid(str.substr(i, j - 1));
				int y = getid(str.substr(i + 1, j - 1));
				v[x].insert(z);
				v[y].insert(z);
			}
		}
		sort(key.begin(), key.end());
		key.resize(unique(key.begin(), key.end()) - key.begin());
		for (auto& x : key) val[x]++;
	}
	auto [sum1, sum2, o] = dfs(0);
	if (o == 1) puts("First");
	else puts("Second");
	printf("%d %d\n", sum2, sum1);
	return 0;
}