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
char str[N];
const int key = 'B' ^ 'G';
set<int> s;
set<tuple<int, int, int>> sp;
int w[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 0; i <= n + 1; i++) s.insert(i);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i < n; i++)
	{
		if ((str[i] ^ str[i + 1]) == key)
		{
			sp.emplace(abs(w[i] - w[i + 1]), i, i + 1);
		}
	}
	vector<pair<int, int>> ans;
	while (!sp.empty())
	{
		int l, r;
		tie(ignore, l, r) = *sp.begin();
		sp.erase(*sp.begin());
		if (!s.count(l) || !s.count(r)) continue;
		s.erase(l);
		s.erase(r);
		ans.emplace_back(l, r);
		auto iter = s.upper_bound(r);
		int y = *iter;
		iter--;
		int x = *iter;
		if ((str[x] ^ str[y]) == key)
		{
			sp.emplace(abs(w[x] - w[y]), x, y);
		}
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}