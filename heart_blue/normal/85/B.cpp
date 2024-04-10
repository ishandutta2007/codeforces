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
void check(vector<pair<LL, LL>>& vp, int k, int t)
{
	sort(vp.begin(), vp.end());
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	for (auto& p : vp)
	{
		while (!pq.empty() && pq.top() <= p.second)
		{
			k++;
			pq.pop();
		}
		if (k > 0)
		{
			k--;
			p.second += t;
			pq.push(p.second);
			continue;
		}
		p.second = max(p.second, pq.top());
		pq.pop();
		p.second += t;
		pq.push(p.second);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k1, k2, k3;
	int t1, t2, t3;
	scanf("%d%d%d", &k1, &k2, &k3);
	scanf("%d%d%d", &t1, &t2, &t3);
	vector<pair<LL, LL>> vp;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, x);
	}
	check(vp, k1, t1);
	check(vp, k2, t2);
	check(vp, k3, t3);
	LL ans = 0;
	for (auto& p : vp)
		ans = max(ans, p.second - p.first);
	printf("%lld\n", ans);
	return 0;
}