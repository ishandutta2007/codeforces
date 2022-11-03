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
int a[N];
int pre[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	if (d == 1)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	a[0] = -1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);
	int to = 0;
	flag[0] = 1;
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0) continue;
		if (a[i + 1] - a[i] - 2 >= s)
		{
			to = max(a[i + 1] - 1 + d, to);
			while (ptr <= n && to > a[ptr])
			{
				flag[ptr] = 1;
				pre[ptr] = i;
				ptr++;
			}
		}
	}
	if (flag[n] == 0)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	vector<pair<int, int>> ans;
	int o = n;
	a[n + 1] = m + 1;
	while (1)
	{
		ans.push_back({ 1,a[o + 1] - a[o] - 2 });
		if (o == 0) break;
		int p = pre[o];
		ans.push_back({ 0,a[o] - a[p + 1] + 2 });
		o = p;
	}
	reverse(ans.begin(), ans.end());
	vector<string> vs = { "JUMP","RUN" };
	for (auto &p : ans)
	{
		if (p.second == 0) break;
		printf("%s %d\n", vs[p.first].c_str(), p.second);
	}
	return 0;
}