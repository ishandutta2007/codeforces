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
const int N = 4e5 + 10;
int a[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, int> mc;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		v[i].emplace_back(n + 1);
		reverse(v[i].begin(), v[i].end());
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int o = v[a[i]].back();
		v[a[i]].pop_back();
		if (mc.count(a[i]))
		{
			s.erase(make_pair(o, a[i]));
			s.emplace(v[a[i]].back(), a[i]);
			continue;
		}
		if (mc.size() == k)
		{
			auto p = *s.rbegin();
			s.erase(p);
			mc.erase(p.second);
		}
		mc[a[i]] = 1;
		s.emplace(v[a[i]].back(), a[i]);
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}