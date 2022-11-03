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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
pair<int, int> vp[N];
int in[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	b = min(b, n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &vp[i].first, &vp[i].second);
	LL sum = 0;
	sort(vp + 1, vp + n + 1);
	reverse(vp + 1, vp + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum += vp[i].second;
	}
	using Node = pair<int, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 1; i <= n; i++)
	{
		in[i] = 1;
		int o = max(0, vp[i].first - vp[i].second);
		pq.emplace(o, i);
		in[i] = 1;
		sum += o;
	}
	while (pq.size() > b)
	{
		auto [o, id] = pq.top();
		pq.pop();
		sum -= o;
		in[id] = 0;
	}
	LL ans = sum;
	for (int i = 1; i <= n; i++)
	{
		if (in[i])
		{
			LL o1 = max(0LL, 1LL * vp[i].first - vp[i].second);
			LL o2 = max(0LL, (1LL << a) * vp[i].first - vp[i].second);
			ans = max(ans, sum + o2 - o1);
		}
		else
		{
			if (pq.empty()) continue;
			int j = pq.top().second;
			LL o1 = max(0LL, 1LL * vp[j].first - vp[j].second);
			LL o2 = max(0LL, (1LL << a) * vp[i].first - vp[i].second);
			ans = max(ans, sum + o2 - o1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}