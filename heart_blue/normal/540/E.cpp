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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class BIT
{
public:
	int a[N];
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} bt;
vector<int> refrain(vector<int>& v)
{
	auto key = v;
	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());
	for (auto& x : v)
	{
		x = lower_bound(key.begin(), key.end(), x) - key.begin() + 1;
	}
	return key;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (mc[a] == 0) mc[a] = a;
		if (mc[b] == 0) mc[b] = b;
		swap(mc[a], mc[b]);
	}
	vector<int> v;
	for (auto& p : mc)
	{
		v.push_back(p.second);
	}
	auto key = refrain(v);
	LL ans = 0;
	for (auto& p : mc)
	{
		auto [a, b] = p;
		if (a != b)
		{
			int maxv = max(a, b);
			int minv = min(a, b);
			int tot = maxv - minv + 1;
			int sz = upper_bound(key.begin(), key.end(), maxv) - lower_bound(key.begin(), key.end(), minv);
			ans += tot - sz;
		}
		int x = lower_bound(key.begin(), key.end(), b) - key.begin() + 1;
		bt.add(x, 1);
		ans += bt.sum(N - 1) - bt.sum(x);
	}
	printf("%lld\n", ans);
	return 0;
}