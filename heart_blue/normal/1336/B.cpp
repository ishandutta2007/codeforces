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
LL sum(LL x, LL y, LL z)
{
	return 2 * (x * x + y * y + z * z - x * y - x * z - y * z);
}
LL solve(vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
	int p1 = 0;
	int p3 = 0;
	LL ans = 8 * INF * INF;
	for (auto& x : v2)
	{
		while (p1 < v1.size() && v1[p1] <= x) p1++;
		while (p3 < v3.size() && v3[p3] < x) p3++;
		if (p1 == 0) continue;
		if (p3 == v3.size()) break;
		ans = min(ans, sum(x, v1[p1 - 1], v3[p3]));
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<int> v[3];
		for (int i = 0; i < 3; i++)
		{
			int sz;
			scanf("%d", &sz);
			v[i].resize(sz);
		}
		for (int i = 0; i < 3; i++)
		{
			for (auto& x : v[i])
				scanf("%d", &x);
			sort(v[i].begin(), v[i].end());
		}
		int a[3] = { 0,1,2 };
		LL ans = 8 * INF * INF;
		do
		{
			ans = min(ans, solve(v[a[0]], v[a[1]], v[a[2]]));
		} while (next_permutation(a, a + 3));
		printf("%lld\n", ans);
	}
	return 0;
}