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
const double pi = acos(-1.0);
//double sinv[N];
double tanv[N];
double maxv[N];
void init()
{
	//sinv[0] = pi / 2;
	//for (int i = 1; i < N; i++) sinv[i] = asin(1.0 / i);
	tanv[0] = pi;
	for (int i = 1; i < N; i++) tanv[i] = 2 * atan2(1, i);
	for (int i = 0; i < N; i++) maxv[i] = tanv[i];
}
inline double getans(LL x, LL y)
{
	if (x > y) swap(x, y);
	if (y - x > 1) return 0;
	if (x >= N) return 0;
	if (x == y) return tanv[x];
	else return tanv[x + 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	scanf("%d%d", &n, &m);
	vector<LL> v(n);
	for (auto &x : v) scanf("%lld", &x);
	scanf("%d", &m);
	vector<LL> v2;
	v2.push_back(-INF * INF);
	v.push_back(INF*INF);
	int ptr = 0;
	while (m--)
	{
		int x;
		scanf("%d", &x);
		while (x >= v[ptr] + 1)
		{
			v2.push_back(v[ptr++]);
		}
		double l = x - v2.back() - 1;
		double r = v[ptr] - x;
		if (l > r) swap(l, r);
		double ans = getans(l, r);
		ans = max({ ans,atan2(1,l),atan2(1,r) });
		int p = v2.size() - 1;
		for (int i = ptr; i + 1 < v.size(); i++)
		{
			if (maxv[v[i] - x] <= ans) break;
			while (p > 0 && x - v2[p] - 1 < v[i] - x - 1) p--;
			ans = max({ ans,
				getans(v[i] - x,x - v2[p] - 1),
				p <= 0 ? 0 : getans(v[i] - x,x - v2[p - 1] - 1),
				p + 1 == v2.size() ? 0 : getans(v[i] - x,x - v2[p + 1] - 1) });
		}
		printf("%.15f\n", ans);
	}
	return 0;
}