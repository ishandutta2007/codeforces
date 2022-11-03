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
const int N = 1e7 + 10;
int flag[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
LL sum(LL x)
{
	return x * (x + 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, a, b;
	cin >> m >> a >> b;
	int g = gcd(a, b);
	int rest = m % g;
	m /= g;
	a /= g;
	b /= g;
	LL ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	flag[0] = 1;
	int cnt = 0;
	while (1)
	{
		int limit = pq.top();
		pq.pop();
		if (limit > m) break;
		queue<int> q;
		q.push(limit);
		flag[limit] = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			cnt++;
			if (x + a > limit)
			{
				pq.emplace(x + a);
			}
			else
			{
				if (!flag[x + a])
				{
					flag[x + a] = 1;
					q.push(x + a);
				}
			}
			if (x - b >= 0 && !flag[x - b])
			{
				flag[x - b] = 1;
				q.push(x - b);
			}
		}
		if (cnt == limit + 1 && limit != 0)
		{
			ans += sum(m) - sum(limit - 1) + (m - limit + 1);
			cnt = m + 1;
			break;
		}
		int l = limit;
		int r = min(m, pq.top() - 1);
		ans += (r - l + 1LL) * cnt;
	}
	ans = (ans - cnt) * g + (rest + 1LL) * cnt;
	printf("%lld\n", ans);
	return 0;
}