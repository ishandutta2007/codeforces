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
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	if (m & 1)
	{
		puts("No");
		return 0;
	}
	int maxv = 0;
	priority_queue <pair<int, int>> pq;
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sz[i]);
		if(sz[i]) pq.emplace(sz[i], i);
	}
	while (!pq.empty())
	{
		int x = pq.top().second;
		pq.pop();
		if (pq.size() < sz[x]) puts("No"), exit(0);
		vector<int> v;
		while (v.size() < sz[x])
		{
			v.emplace_back(pq.top().second);
			pq.pop();
			sz[v.back()]--;
			ans.emplace_back(x, v.back());
		}
		for (auto& x : v)
		{
			if (sz[x])
				pq.emplace(sz[x], x);
		}
	}
	puts("Yes");
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}