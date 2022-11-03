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
const int N = 3e3 + 10;
vector<int> vp[N];
vector<int> check(vector<int>& v, int len)
{
	deque<int> q;
	vector<int> ret;
	for (int i = 0; i < v.size(); i++)
	{
		while (!q.empty() && v[i] <= v[q.back()])
			q.pop_back();
		while (!q.empty() && i - q.front() + 1 > len)
			q.pop_front();
		q.push_back(i);
		if (i + 1 >= len)
			ret.push_back(v[q.front()]);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	LL g, x, y, z;
	scanf("%lld%lld%lld%lld", &g, &x, &y, &z);
	for (int i = 1; i <= n; i++)
	{
		vector<int> v;
		for (int j = 1; j <= m; j++)
		{
			v.push_back(g);
			g = (g * x + y) % z;
		}
		v = check(v, b);
		for (int j = 0; j < v.size(); j++)
		{
			vp[j].push_back(v[j]);
		}
	}
	LL ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (vp[i].empty()) break;
		auto v = check(vp[i], a);
		for (auto& x : v)
			ans += x;
	}
	printf("%lld\n", ans);
	return 0;
}