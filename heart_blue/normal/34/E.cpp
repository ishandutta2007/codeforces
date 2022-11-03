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
double pos[N];
const double eps = 1e-10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	double T;
	scanf("%d%lf", &n, &T);
	vector<tuple<double, double, int, int>> vp;
	for (int i = 0; i < n; i++)
	{
		int x, v, m;
		scanf("%d%d%d", &x, &v, &m);
		vp.emplace_back(x, v, m, i);
	}
	sort(vp.begin(), vp.end());
	int cnt = 0;
	while (T > eps)
	{
		double minv = 1e20;
		int id = -1;
		for (int i = 0; i + 1 < vp.size(); i++)
		{
			auto [x1, v1, m1, id1] = vp[i];
			auto [x2, v2, m2, id2] = vp[i + 1];
			if (v1 - v2 < eps) continue;
			double t = (x2 - x1) / (v1 - v2);
			if (t < eps) t = 0;
			if (minv > t)
			{
				minv = t;
				id = i;
			}
		}
		if (id != -1)
		{
			if (minv > T)
				minv = T, id = -1;
		}
		if (minv > T)
			minv = T;
		for (auto& [x, v, m, id] : vp)
		{
			x += v * minv;
		}
		T -= minv;
		if (id == -1) break;
		auto& [x1, v1, m1, id1] = vp[id];
		auto& [x2, v2, m2, id2] = vp[id + 1];
		x1 = x2 = (x1 + x2) / 2;
		tie(v1, v2) = make_pair((m1 - m2) * v1 + 2 * m2 * v2, (m2 - m1) * v2 + 2 * m1 * v1);
		v1 /= m1 + m2;
		v2 /= m1 + m2;
	}
	for (auto& [x, v, m, id] : vp)
		pos[id] = x;
	for (int i = 0; i < n; i++)
		printf("%.15f\n", pos[i]);
	return 0;
}