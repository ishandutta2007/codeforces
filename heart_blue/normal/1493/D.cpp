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
const int N = 2e5 + 10;
map<int, int> mc1[N], mc2[N];
set<pair<int, int>> sp[N];
int p[N];
LL ans = 1;
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (mc1[i].empty())
		{
			mc1[i][i] = 1;
			p[k++] = i;
		}
		for (int j = 0; i * p[j] < N && j < k; j++)
		{
			mc1[i * p[j]] = mc1[i];
			mc1[i * p[j]][p[j]]++;
			if (i % p[j] == 0) break;
		}
	}
}
void add(int id, int x, int n)
{
	for (auto [d, cnt] : mc1[x])
	{
		int cur = 0; 
		if (!sp[d].empty())
		{
			cur = sp[d].begin()->first;
			if (sp[d].size() != n) 
				cur = 0;
		}
		sp[d].erase(make_pair(mc2[id][d], id));
		mc2[id][d] += cnt;
		sp[d].insert(make_pair(mc2[id][d], id));
		if (sp[d].size() != n) continue;
		int nex = sp[d].begin()->first;
		while (cur < nex)
		{
			cur++;
			ans = ans * d % INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	init();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(i, x, n);
	}
	while (q--)
	{
		int id, x;
		scanf("%d%d", &id, &x);
		add(id, x, n);
		printf("%lld\n", ans);
	}
	return 0;
}