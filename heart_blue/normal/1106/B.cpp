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
int a[N], c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		tot += a[i];
	}
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 1; i <= n; i++) pq.emplace(c[i], i);
	while (m--)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		if (d > tot)
		{
			tot = 0;
			puts("0");
			continue;
		}
		int o = min(a[t], d);
		LL cost = 1LL * o * c[t];
		a[t] -= o;
		d -= o;
		tot -= o;
		while (d && !pq.empty())
		{
			int x, pos;
			tie(x, pos) = pq.top();
			if (a[pos] == 0)
			{
				pq.pop();
				continue;
			}
			int o = min(d, a[pos]);
			a[pos] -= o;
			d -= o;
			tot -= o;
			cost += 1LL * x * o;
		}
		printf("%lld\n", cost);
	}
	return 0;
}