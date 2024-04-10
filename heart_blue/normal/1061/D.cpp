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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	vector<int> v;
	vector<pair<int, int>> vp;
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		vp.emplace_back(l, r);
	}
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	sort(vp.begin(), vp.end());
	LL ans = 0;
	for (auto& [l, r] : vp)
	{
		while (!pq2.empty() && pq2.top() <= l)
		{
			pq1.push(pq2.top());
			pq2.pop();
		}
		if (!pq1.empty() && 1LL * (l - pq1.top() + 1) * y < x)
		{
			ans += 1LL * (r - pq1.top() + 1) * y % INF;
			pq1.pop();
			pq2.push(r + 1);
		}
		else
		{
			ans += 1LL * (r - l) * y % INF;
			ans += x;
			pq2.push(r + 1);
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}