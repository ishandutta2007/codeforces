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
class BIT
{
	int a[N];
public:
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
			if (ret >= INF)
				ret -= INF;
		}
		return ret;
	}
	void add(int x, int val)
	{
		if (val < 0) val += INF;
		while (x < N)
		{
			a[x] += val;
			if (a[x] >= INF)
				a[x] -= INF;
			x += x & -x;
		}
	}
} b;
vector<pair<int, int>> vp;
int refrain(vector<pair<int, int>>& vp, int n)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(n);
	for (auto& p : vp)
		v.push_back(p.first), v.push_back(p.second);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& p : vp)
	{
		p.first = lower_bound(v.begin(), v.end(), p.first) - v.begin() + 1;
		p.second = lower_bound(v.begin(), v.end(), p.second) - v.begin() + 1;
	}
	return v.size();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	while (k--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		vp.emplace_back(r, l);
	}
	sort(vp.begin(), vp.end());
	int sz = refrain(vp, n);
	b.add(1, 1);
	for (auto& p : vp)
	{
		int l, r;
		tie(r, l) = p;
		b.add(r, b.sum(r - 1) - b.sum(l - 1));
	}
	int ans = b.sum(sz) - b.sum(sz - 1);
	if (ans < 0) ans += INF;
	printf("%d\n", ans);
	return 0;
}