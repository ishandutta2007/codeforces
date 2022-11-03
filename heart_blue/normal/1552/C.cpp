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
const int N = 2e2 + 10;
int check2(int l1, int r1, int l2, int r2)
{
	if (l2 > l1 && l2 < r1 && !(r2 > l1 && r2 < r1))
		return 1;
	else
		return 0;
}
int check(pair<int, int>& p1, pair<int, int>& p2)
{
	auto [l1, r1] = p1;
	auto [l2, r2] = p2;
	if (l1 > r1) swap(l1, r1);
	if (l2 > r2) swap(l2, r2);
	return check2(l1, r1, l2, r2) |
		check2(l1, r1, r2, l2) |
		check2(l2, r2, l1, r1) |
		check2(l2, r2, r1, l1);
}
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(flag, 0);
		vector<int> v;
		vector<pair<int, int>> vp;
		int n, m;
		scanf("%d%d", &n, &m);
		while (m--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp.emplace_back(x, y);
			flag[x] = 1;
			flag[y] = 1;
		}
		for (int i = 1; i <= 2 * n; i++)
		{
			if (flag[i]) continue;
			v.push_back(i);
		}
		m = v.size() / 2;
		for (int i = 0; i < m; i++)
		{
			vp.emplace_back(v[i], v[i + m]);
		}
		int ans = 0;
		for (int i = 0; i < vp.size(); i++)
		{
			for (int j = i + 1; j < vp.size(); j++)
			{
				ans += check(vp[i], vp[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}