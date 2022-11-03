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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e4 + 10;
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
		map<int, pair<int, int>> mc;
		while (n--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			mc[x].first++;
			mc[x].second += y;
		}
		vector<pair<int, int>> v;
		priority_queue<int> pq;
		for (auto& p : mc)
			v.push_back(p.second);
		sort(v.rbegin(), v.rend());
		int ans1 = 0;
		int ans2 = 0;
		int cur = INF;
		for (auto& p : v)
		{
			if (cur < p.first)
			{
				pq.push(p.second);
				continue;
			}
			while (cur > p.first && !pq.empty())
			{
				ans1 += cur;
				ans2 += min(cur, pq.top());
				pq.pop();
				cur--;
			}
			if (cur <= 0) break;
			cur = min(cur, p.first);
			pq.push(p.second);
			ans1 += cur;
			ans2 += min(cur, pq.top());
			cur--;
			pq.pop();
		}
		while (cur > 0 && !pq.empty())
		{
			ans1 += cur;
			ans2 += min(cur, pq.top());
			pq.pop();
			cur--;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}