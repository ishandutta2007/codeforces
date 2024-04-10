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
const int N = 1e5 + 10;
int lsum[N];
int rsum[N];
int usum[N];
int dsum[N];
int sum1[N];
int sum2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector < pair<pair<int, int>, pair<int, int>> > vp;
	int k;
	scanf("%d", &k);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= k; i++)
	{
		pair<int, int> p1, p2;
		scanf("%d%d%d%d", &p1.first, &p1.second, &p2.first, &p2.second);
		if (p1 > p2)
			swap(p1, p2);
		auto [x1, y1] = p1;
		auto [x2, y2] = p2;
		if (x1 == x2)
		{
			lsum[y1]++;
			rsum[y2]++;
			sum1[y1]++;
			usum[x1]++;
			dsum[x1]++;
		}
		else
		{
			usum[x1]++;
			dsum[x2]++;
			sum2[x1]++;
			lsum[y1]++;
			rsum[y1]++;
		}
		vp.emplace_back(p1, p2);
	}
	for (int i = 1; i < N; i++) lsum[i] += lsum[i - 1];
	for (int i = 1; i < N; i++) usum[i] += usum[i - 1];
	for (int i = N - 2; i >= 0; i--) rsum[i] += rsum[i + 1];
	for (int i = N - 2; i >= 0; i--) dsum[i] += dsum[i + 1];
	int ucnt, dcnt, lcnt, rcnt;
	scanf("%d%d%d%d", &ucnt, &dcnt, &lcnt, &rcnt);
	int ans = -1;
	for (int i = 0; i < vp.size(); i++)
	{
		auto [p1, p2] = vp[i];
		auto [x1, y1] = p1;
		auto [x2, y2] = p2;
		if (x1 == x2)
		{
			if (usum[x1 - 1] != ucnt) continue;
			if (dsum[x1 + 1] != dcnt) continue;
			if (lsum[y1] - 1 != lcnt) continue;
			if (rsum[y2] - 1 != rcnt) continue;
			ans = i + 1;
			break;
		}
		else
		{
			int key = sum2[x1] - 1;
			if (usum[x1] - 1 != ucnt) continue;
			if (dsum[x2] - 1 != dcnt) continue;
			if (lsum[y1 - 1] != lcnt) continue;
			if (rsum[y1 + 1] != rcnt) continue;
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}