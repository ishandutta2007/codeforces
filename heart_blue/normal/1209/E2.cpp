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
int a[N];
int b[N];
void refrain(vector<int>& v)
{
	int pos = max_element(v.begin(), v.end()) - v.begin();
	vector<int> ret = v;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = ret[(i + pos) % v.size()];
	}
}
int rot(int x, int n)
{
	return ((x << (n - 1)) | (x >> 1)) & ((1 << n) - 1);
}
void build(vector<int>& v)
{
	int sz = v.size();
	int tot = 1 << sz;
	for (int i = 0; i < sz; i++)
		b[1 << i] = v[i];
	for (int i = 1; i < tot; i++)
		b[i] = b[i - (i & -i)] + b[i & -i];
	for (int i = 1; i < tot; i++)
	{
		int maxv = 0;
		int x = i;
		for (int j = 0; j < sz; j++)
		{
			maxv = max(maxv, b[x]);
			x = rot(x, sz);
		}
		b[i] = maxv;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int>> vp(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &vp[j][i]);
			}
		}
		for (auto& v : vp)
			refrain(v);
		sort(vp.begin(), vp.end(), [](vector<int>& v1, vector<int>& v2)->bool
			{
				return v1[0] > v2[0];
			});
		while (vp.size() > n) vp.pop_back();
		MEM(a, 0);
		for (auto& v : vp)
		{
			build(v);
			int tot = 1 << n;
			for (int i = tot - 1; i >= 0; i--)
			{
				for (int s = i; s >= 0; s = (s - 1) & i)
				{
					a[i] = max(a[i], a[s] + b[s ^ i]);
					if (s == 0) break;
				}
			}
		}
		printf("%d\n", a[(1 << n) - 1]);
	}
	return 0;
}