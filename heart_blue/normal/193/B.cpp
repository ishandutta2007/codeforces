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
const int N = 5e2 + 10;
int n, u, r;
int a[N];
int b[N];
int k[N];
int p[N];
LL ans = -INF * INF;
vector<int> add1(const vector<int>& v)
{
	auto ret = v;
	for (int i = 0; i < v.size(); i++)
		ret[i] ^= b[i];
	return ret;
}
vector<int> add2(const vector<int>& v)
{
	auto ret = v;
	for (int i = 0; i < v.size(); i++)
		ret[i] = v[p[i]] + r;
	return ret;
}
void dfs(const vector<int>& v, int rest, int last = -1)
{
	if (rest % 2 == 0)
	{
		LL sum = 0;
		for (int i = 0; i < v.size(); i++)
			sum += 1LL * v[i] * k[i];
		ans = max(ans, sum);
	}
	if (rest == 0) return;
	if (last != 0) dfs(add1(v), rest - 1, 0);
	dfs(add2(v), rest - 1, 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &u, &r);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) scanf("%d", &k[i]);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
	vector<int> v(a, a + n);
	dfs(v, u);
	printf("%lld\n", ans);
	return 0;
}