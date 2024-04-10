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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			vp.emplace_back(i + j, i);
	}
	sort(vp.begin(), vp.end());
	while (vp.size() > k) vp.pop_back();
	LL ans = 0;
	reverse(vp.begin(), vp.end());
	for (auto [len, i] : vp)
		ans += len - 1;
	printf("%d\n", ans);
	for (auto [len, x] : vp)
	{
		int y = len - x;
		for (int i = 1; i <= x; i++) printf("(%d,%d) ", i, 1);
		for (int j = 2; j <= y; j++) printf("(%d,%d) ", x, j);
		puts("");
	}

	return 0;
}