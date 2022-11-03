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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<LL> build(int n)
{
	vector<LL> ret;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i) continue;
		ret.push_back(i);
		if (i * i != n) ret.push_back(n / i);
	}
	sort(ret.begin(), ret.end());
	return ret;
}
vector<LL> combine(vector<LL> v1, vector<LL> v2)
{
	vector<LL> ret;
	for (auto& x : v1)
	{
		for (auto& y : v2)
			ret.push_back(x * y);
	}
	sort(ret.begin(), ret.end());
	return ret;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		auto v = combine(build(a), build(b));
		int ans1 = -1, ans2 = -1;
		for (auto& o : v)
		{
			LL x = (a + 1 + o - 1) / o * o;
			if (x > c) continue;
			LL y = a * b / gcd(1LL * a * b, x);
			y = (b + 1 + y - 1) / y * y;
			if (y > d) continue;
			ans1 = x, ans2 = y;
			break;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}