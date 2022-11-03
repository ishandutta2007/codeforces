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
const int N = 5e3 + 10;
vector<double> vd;
int flag = 0;
vector<int> check(double x, int sz)
{
	vector<int> v;
	int cur = 0;
	double tot = x;
	while (v.size() < sz)
	{
		int o = tot / 10;
		cur += o;
		v.push_back(cur);
		tot -= o * 10;
		if (v.size() == sz) break;
		tot += x;
	}
	if (flag) vd.push_back(tot);
	return v;
}
double solve(vector<int>& v1, int o = 0)
{
	double l = 10 + 1e-10;
	double r = INF;
	int cnt = 200;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		auto v2 = check(mid, v1.size());
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] < v2[i])
			{
				r = mid;
				break;
			}
			if (v1[i] > v2[i])
			{
				l = mid;
				break;
			}
		}
		if (v1 != v2) continue;
		if (o == 0) l = mid;
		else r = mid;
	}
	return l;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	double key1 = solve(v, 0);
	double key2 = solve(v, 1);
	flag = 1;
	if (key1 > key2) swap(key1, key2);
	int ans1 = check(key1, n + 1).back();
	int ans2 = check(key2, n + 1).back();
	if (abs(vd[0] - 10) <= 1e-8) ans1++;
	if (ans1 == ans2) puts("unique"), printf("%d\n", ans1), exit(0);
	else puts("not unique");
	return 0;
}