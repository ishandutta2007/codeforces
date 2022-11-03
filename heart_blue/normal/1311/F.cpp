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
const int N = 3e5 + 10;
void init(vector<pair<int, int>>& vp)
{
	vector<int> v;
	for (auto& p : vp)
		v.push_back(p.second);
	sort(v.begin(), v.end());
	for (auto& p : vp)
	{
		p.second = lower_bound(v.begin(), v.end(), p.second) - v.begin() + 1;
	}
}
class BIT
{
public:
	LL a[N];
	void add(int x, LL val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b1, b2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	for (auto& p : vp) scanf("%d", &p.first);
	for (auto& p : vp) scanf("%d", &p.second);
	init(vp);
	LL ans = 0;
	sort(vp.begin(), vp.end());
	for (auto& p : vp)
	{
		b1.add(p.second, 1);
		b2.add(p.second, p.first);
		ans += b1.sum(p.second) * p.first - b2.sum(p.second);
	}
	printf("%lld\n", ans);
	return 0;
}