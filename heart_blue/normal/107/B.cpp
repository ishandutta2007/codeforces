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
int a[N];
double C(int a, int b, int c, int d, int e, int f)
{
	if (a < b) return 0;
	if (c < d) return 0;
	vector<int> v1, v2;
	while (a&&b) v1.push_back(a--), v2.push_back(b--);
	while (c&&d) v1.push_back(c--), v2.push_back(d--);
	while (e&&f) v1.push_back(e--), v2.push_back(f--);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	double ret = 1;
	while (!v1.empty() && !v2.empty())
	{
		ret = ret*v1.back() / v2.back();
		v1.pop_back();
		v2.pop_back();
	}
	for (auto &x : v1) ret *= x;
	for (auto &x : v2) ret /= x;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, h;
	cin >> n >> m >> h;
	int tot = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	int rest = a[h];
	if (tot < n)
	{
		puts("-1");
		return 0;
	}
	double ans = 0;
	for (int i = 1; i <= min(rest - 1, n - 1); i++)
		ans += C(rest - 1, i, tot - rest, n - i - 1, n - 1, tot - 1);
	printf("%.15f\n", ans);
	return 0;
}