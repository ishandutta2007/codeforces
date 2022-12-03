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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		priority_queue<tuple<int, int, int>> pq;
		int minv = INF;
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			minv = min(minv, x);
			pq.emplace(x, x, 1);
		}
		while (!pq.empty())
		{
			auto [val, x, o] = pq.top();
			pq.pop();
			ans = min(ans, val - minv);
			if (val == 0) break;
			o = x / (x / o) + 1;
			if (o > k) break;
			val = x / o;
			minv = min(minv, val);
			pq.emplace(val, x, o);
		}
		printf("%d\n", ans);
	}
	return 0;
}