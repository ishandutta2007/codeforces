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
vector<vector<int>> ans;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		s.emplace(-x, i);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &a[i]);
		a[i] = -a[i];
	}
	while (!s.empty())
	{
		vector<int> v;
		while (-a[1] > v.size())
		{
			int x = lower_bound(a + 1, a + k + 1, -int(v.size())) - a - 1;
			auto iter = s.lower_bound(make_pair(-x, -1));
			if (iter == s.end()) break;
			v.push_back(-iter->first);
			s.erase(*iter);
		}
		ans.push_back(v);
	}
	printf("%d\n", ans.size());
	for (auto& v : ans)
	{
		printf("%d", v.size());
		for (auto& x : v)
			printf(" %d", x);
		puts("");
	}
	return 0;
}