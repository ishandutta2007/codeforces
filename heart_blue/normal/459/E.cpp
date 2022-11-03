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
const int N = 1e5 + 10;
int ans[N * 3];
vector<pair<int, int>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[w].push_back({ x,y });
	}
	MEM(ans, 0);
	for (int i = 1; i < N; i++)
	{
		map<int, int> mc;
		for (auto &p : vp[i])
		{
			int x, y;
			tie(x, y) = p;
			if (!mc.count(x)) mc[x] = ans[x];
			if (!mc.count(y)) mc[y] = ans[y];
			ans[y] = max(ans[y], mc[x] + 1);
		}
	}
	int maxv = 0;
	for (int i = 1; i <= n; i++) maxv = max(maxv, ans[i]);
	printf("%d\n", maxv);
	return 0;
}