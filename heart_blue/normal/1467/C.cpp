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
const int N = 3e5 + 10;

LL sum(vector<int>& v)
{
	LL ret = 0;
	for (auto& x : v)
		ret += x;
	return ret;
}
LL solve1(vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
	return sum(v1) - sum(v2) + sum(v3);
}
LL solve2(vector<int>& v1, vector<int>& v2, vector<int>& v3)
{
	if (v2.size() == 1 || v3.size() == 1) return 0;
	return sum(v1) + sum(v2) + sum(v3) - 2 * v2[0] - 2 * v3[0];
}
vector<int> v[3];
int a[] = { 0,1,2 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sz[3];
	scanf("%d%d%d", &sz[0], &sz[1], &sz[2]);
	for (int i = 0; i < 3; i++)
	{
		v[i].resize(sz[i]);
		for (auto& x : v[i])
			scanf("%d", &x);
		sort(v[i].begin(), v[i].end());
	}
	LL ans = 0;
	do
	{
		ans = max(ans, solve1(v[a[0]], v[a[1]], v[a[2]]));
		ans = max(ans, solve2(v[a[0]], v[a[1]], v[a[2]]));
	} while (next_permutation(a, a + 3));
	printf("%lld\n", ans);
	return 0;
}