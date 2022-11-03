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
const int N = 1e6 + 10;
LL lcost[N];
LL rcost[N];
vector<pair<int, int>> in[N];
vector<pair<int, int>> out[N];
int flag[N];
int minv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int K = 0;
	while (m--)
	{
		int d, u, v, cost;
		cin >> d >> u >> v >> cost;
		K = max(d, K);
		if (u != 0) in[d].push_back({ u,cost });
		else out[d].push_back({ v,cost });
	}
	LL inf = LL(n) * 0x3f3f3f3f;
	MEM(flag, 0);
	int cur = 0;
	MEM(minv, 0x3f);
	LL cost = LL(n)*minv[1];
	for (int i = 1; i <= K; i++)
	{
		for (auto &p : in[i])
		{
			if (!flag[p.first]) flag[p.first] = 1, cur++;
			cost -= max(0, minv[p.first] - p.second);
			minv[p.first] = min(minv[p.first], p.second);
		}
		if (cur == n) lcost[i] = cost;
		else lcost[i] = inf;
	}
	MEM(flag, 0);
	cur = 0;
	MEM(minv, 0x3f);
	cost = LL(n)*minv[1];
	for (int i = K; i > 0; i--)
	{
		for (auto &p : out[i])
		{
			if (!flag[p.first]) flag[p.first] = 1, cur++;
			cost -= max(0, minv[p.first] - p.second);
			minv[p.first] = min(minv[p.first], p.second);
		}
		if (cur == n) rcost[i] = cost;
		else rcost[i] = inf;
	}
	LL ans = inf;
	for (int i = 1; i + k < K; i++)
	{
		ans = min(ans, lcost[i] + rcost[i + k + 1]);
	}
	if (ans >= inf) ans = -1;
	cout << ans << endl;
	return 0;
}