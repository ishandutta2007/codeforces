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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e1 + 10;

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
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pq.emplace(x, i);
		}
		vector<pair<int, int>> ans;
		while (pq.size() > 1)
		{
			int cnt2, y;
			tie(cnt2, y) = pq.top();
			pq.pop();
			int cnt1, x;
			tie(cnt1, x) = pq.top();
			pq.pop();
			if (cnt2 == 0) continue;
			if (cnt1 == 0) continue;
			cnt1--, cnt2--;
			ans.emplace_back(x, y);
			if (cnt2 > 0)
				pq.emplace(cnt2, y);
			if (cnt1 > 0)
				pq.emplace(cnt1, x);
		}
		printf("%d\n", ans.size());
		for (auto [x, y] : ans)
			printf("%d %d\n", x, y);
	}
	return 0;
}