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
const int N = 5e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<tuple<int, int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == 0)
			{
				vp.emplace_back(i + 1, n, i);
			}
			else
			{
				vp.emplace_back(i / (x + 1) + 1, i / x, i);
			}
		}
		sort(vp.rbegin(), vp.rend());
		using Node = pair<int, int>;
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		for (int i = 1; i <= n; i++)
		{
			while (!vp.empty())
			{
				auto [l, r, id] = vp.back();
				if (l != i) break;
				pq.emplace(r, id);
				vp.pop_back();
			}
			ans[pq.top().second] = i;
			pq.pop();
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}