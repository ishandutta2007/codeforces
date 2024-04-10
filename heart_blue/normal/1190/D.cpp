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
void refrain(vector<pair<int, int>>& vp)
{
	vector<int> v1, v2;
	for (auto& [x, y] : vp)
	{
		v1.push_back(x);
		v2.push_back(y);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (auto& [x, y] : vp)
	{
		x = lower_bound(v1.begin(), v1.end(), x) - v1.begin() + 1;
		y = lower_bound(v2.begin(), v2.end(), y) - v2.begin() + 1;
	}
}
class BIT
{
	int a[N];
public:
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
} b;
int cnt[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	for (auto& [x, y] : vp)
	{
		scanf("%d%d", &x, &y);
	}
	refrain(vp);
	for (auto& [x, y] : vp)
	{
		v[y].push_back(x);
		if (cnt[x]++ == 0)
			b.add(x, 1);
	}
	LL ans = 0;
	for (int i = 1; i < N; i++)
	{
		v[i].push_back(0);
		v[i].push_back(N);
		sort(v[i].begin(), v[i].end());
		int tot = b.sum(N - 1);
		ans += 1LL * tot * (tot + 1) / 2;
		for (int j = 1; j < v[i].size(); j++)
		{
			int l = v[i][j - 1];
			int r = v[i][j];
			int c = b.sum(r - 1) - b.sum(l);
			ans -= 1LL * c * (c + 1) / 2;
		}
		for (auto& x : v[i])
		{
			if (x == 0 || x == N) continue;
			if (cnt[x] -- == 1)
				b.add(x, -1);
		}
	}
	printf("%lld\n", ans);

	return 0;
}