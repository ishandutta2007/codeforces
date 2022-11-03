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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++)
	{
		int t, q;
		scanf("%d%d", &t, &q);
		if (t > m) continue;
		pq.emplace(m - t, q);
	}
	while (pq.size() > 1 && pq.top().first > 0)
	{
		auto [d1, val1] = pq.top(); pq.pop();
		auto [d2, val2] = pq.top(); pq.pop();
		if (d1 == d2)
		{
			pq.emplace(d1 - 1, val1 + val2);
		}
		else
		{
			pq.emplace(d1 - 1, val1);
			pq.emplace(d2, val2);
		}
	}
	printf("%d\n", pq.top().second);
	return 0;
}