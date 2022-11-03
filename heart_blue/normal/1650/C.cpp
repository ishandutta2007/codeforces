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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 20;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<tuple<int, int, int>> vp;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int x, w;
			scanf("%d%d", &x, &w);
			vp.emplace_back(w, x, i);
		}
		sort(vp.begin(), vp.end());
		int l = 0, r = 2 * n - 1;
		LL ans = 0;
		for (int i = 0; i <= r; i++)
		{
			ans += get<0>(vp[i]);
			swap(get<0>(vp[i]), get<1>(vp[i]));
		}
		sort(vp.begin(), vp.begin() + 2 * n);
		printf("%lld\n", ans);
		while (l <= r)
		{
			printf("%d %d\n", get<2>(vp[l++]), get<2>(vp[r--]));
		}
	}
	return 0;
}