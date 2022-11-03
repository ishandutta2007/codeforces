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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, x;
		scanf("%d%d%d", &n, &m, &x);
		using Node = pair<int, int>;
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		for (int i = 1; i <= m; i++)
			pq.emplace(0, i);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			auto [val, pos] = pq.top();
			pq.pop();
			val += x;
			ans[i] = pos;
			pq.emplace(val, pos);
		}
		puts("YES");
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}