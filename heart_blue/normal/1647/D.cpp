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
int tot = 0;
void check(const vector<int>& v, int cur, int x, int d)
{
	if (v[cur] * d > x) return;
	if (x % d) return;
	if (x % d == 0 && x % (1LL * d * d) != 0)
	{
		tot++;
	}
	if (tot >= 2) return;
	for (int i = cur; i < v.size(); i++)
	{
		if (1LL * v[i] * d > x) break;
		if (x % (1LL * v[i] * d)) continue;
		check(v, i, x / v[i] / d, d);
	}
}
vector<int> build(int x, int d)
{
	vector<int> v;
	x /= d;
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i) continue;
		if (i % d) v.push_back(i);
		if (i * i != x && x / i % d) v.push_back(x / i);
	}
	sort(v.begin(), v.end());
	return v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		tot = 0;
		int x, d;
		scanf("%d%d", &x, &d);
		check(build(x, d), 0, x, d);
		if (tot >= 2) puts("YES");
		else puts("NO");
	}
	return 0;
}