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
const int N = 5e1 + 10;

int check(int cnt1, int cnt2, int cnt3, int cnt4, int key3, int key4)
{
	if (key3 < 0 || key4 < 0) return INF;
	vector<pair<int, int>> vp1, vp2;
	vp1.emplace_back(1, cnt1);
	vp1.emplace_back(2, cnt2);
	vp1.emplace_back(3, cnt3);
	vp1.emplace_back(4, cnt4);
	vp2.emplace_back(0, cnt1 + cnt2 + cnt3 + cnt4 - key3 - key4);
	vp2.emplace_back(3, key3);
	vp2.emplace_back(4, key4);
	int ret = 0;
	while (!vp1.empty() && !vp2.empty())
	{
		auto [x, c1] = vp1.back();
		vp1.pop_back();
		auto [y, c2] = vp2.back();
		vp2.pop_back();
		int o = min(c1, c2);
		ret += max(0, x - y) * o;
		c1 -= o;
		c2 -= o;
		if (c1) vp1.emplace_back(x, c1);
		if (c2) vp2.emplace_back(y, c2);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int tot = 0;
	int cnt[5] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		tot += x;
		cnt[x]++;
	}
	if (tot == 1 || tot == 2 || tot == 5)
	{
		puts("-1");
		return 0;
	}
	int ans = INF;
	for (int i = 0; i * 4 <= tot; i++)
	{
		if ((tot - 4 * i) % 3) continue;
		int key4 = i;
		int key3 = (tot - 4 * i) / 3;
		ans = min(ans, check(cnt[1], cnt[2], cnt[3], cnt[4], key3, key4));
	}
	printf("%d\n", ans);
	return 0;
}