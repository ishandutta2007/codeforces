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
const int N = 1e5 + 10;
vector<int> v[N];
int deg[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[y].push_back(x);
		deg[x]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			pq.push(i);
	}
	int cur = n;
	while (!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		ans[x] = cur--;
		for (auto& y : v[x])
		{
			if (deg[y]-- == 1)
				pq.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}