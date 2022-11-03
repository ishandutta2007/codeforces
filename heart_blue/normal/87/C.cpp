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
const int N = 2e5 + 10;
vector<int> vd[N];
int sum[N];
int ans[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			vd[j].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	fill(ans, ans + N, int(INF));
	for (int i = 3; i <= n; i++)
	{
		map<int, int> mc;
		int x = i * 2;
		for (auto& d : vd[i * 2])
		{
			int a = d;
			int b = i * 2 / d - 1;
			if ((a + b) & 1) continue;
			int x = (a + b) / 2;
			int y = (b - a) / 2;
			if (x <= 0 || y < 0) continue;
			if (x - y == 1) continue;
			mc[sum[x] ^ sum[y]] = 1;
			if (sum[x] ^ sum[y]) continue;
			ans[i] = min(ans[i], x - y);
		}
		for (int o = 0; o < N; o++)
		{
			if (!mc.count(o))
			{
				sum[i] = o;
				break;
			}
		}
		sum[i] ^= sum[i - 1];
	}
	if (ans[n] == INF) puts("-1");
	else printf("%d\n", ans[n]);
	return 0;
}