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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
std::random_device rd;
std::mt19937_64 mt(rd());
ULL p[N];
ULL a[N];
ULL b[N];
ULL pre[N];
ULL pos[N];
vector<int> v1[N], v2[N];
void init()
{
	for (int i = 0; i < N; i++)
		p[i] = mt();
}
class BIT
{
public:
	ULL a[N];
	void init()
	{
		MEM(a, 0);
	}
	void add(int x, ULL val)
	{
		while (x < N)
		{
			a[x] ^= val;
			x += x & -x;
		}
	}
	ULL sum(int x)
	{
		ULL ret = 0;
		while (x)
		{
			ret ^= a[x];
			x -= x & -x;
		}
		return ret;
	}
} B;
vector<pair<int, int>> vp1, vp2;
void refrain(vector<pair<int, int>>& vp, vector<int> vv[N])
{
	vector<int> v;
	for (auto& p : vp)
	{
		v.push_back(p.first);
		v.push_back(p.second);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& p : vp)
	{
		p.first = lower_bound(v.begin(), v.end(), p.first) - v.begin() + 1;
		p.second = lower_bound(v.begin(), v.end(), p.second) - v.begin() + 1;
	}
	for (int i = 0; i < vp.size(); i++)
	{
		int l, r;
		tie(l, r) = vp[i];
		vv[l].push_back(-i - 1);
		vv[r].push_back(i + 1);
	}
}
void check(vector<pair<int, int>>& vp, vector<int> v[], ULL a[N])
{
	MEM(pos, 0);
	MEM(pre, 0);
	for (int i = 0; i < N; i++)
	{
		for (auto& x : v[i])
		{
			if (x > 0) pre[i] ^= p[x];
			else pos[i] ^= p[-x];
		}
	}
	for (int i = 1; i < N; i++) pre[i] ^= pre[i - 1];
	for (int i = N - 2; i >= 0; i--) pos[i] ^= pos[i + 1];
	for (int i = 0; i < vp.size(); i++)
	{
		int l, r;
		tie(l, r) = vp[i];
		a[i] = pre[l - 1] ^ pos[r + 1];
	}
}
void solve(int n)
{
	init();
	check(vp1, v1, a);
	check(vp2, v2, b);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != b[i])
			puts("NO"), exit(0);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		vp1.emplace_back(l1, r1);
		vp2.emplace_back(l2, r2);
	}
	refrain(vp1, v1);
	refrain(vp2, v2);
	int cnt = 64;
	while (cnt--)
	{
		solve(n);
	}
	puts("YES");
	return 0;
}