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
const int N = 5e3 + 10;
int v[N][N];
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	set<pair<int, int>> sp;
	int tot = 0;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, x, y, m;
		scanf("%d%d%d%d%d", &sz[i], &a, &x, &y, &m);
		int o = 1;
		v[i][1] = a;
		tot += sz[i];
		int cnt = 0;
		while (o < sz[i])
		{
			int pre = a;
			a = (1LL * a * x + y) % m;
			if (pre > a) cnt++;
			v[i][++o] = a;

		}
		maxv = max(maxv, cnt);
		reverse(v[i] + 1, v[i] + sz[i] + 1);
		sp.emplace(v[i][sz[i]], i);
	}
	printf("%d\n", maxv);
	if (tot > 200000) return 0;
	int pre = -1;
	vector<pair<int, int>> ans;
	while (!sp.empty())
	{
		auto iter = sp.lower_bound(make_pair(pre, -1));
		if (iter == sp.end()) iter = sp.begin();
		int val, o;
		tie(val, o) = *iter;
		sp.erase(iter);
		ans.emplace_back(val, o);
		pre = val;
		sz[o]--;
		if (sz[o] == 0) continue;
		sp.emplace(v[o][sz[o]], o);
	}
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}