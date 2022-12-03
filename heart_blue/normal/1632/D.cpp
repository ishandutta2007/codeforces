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
const int N = 1e3 + 10;
void check(vector<tuple<int, int, int>>& vp, int k)
{
	for (auto& [l, r, g] : vp)
	{
		if (k - r + 1 <= g && g <= k - l + 1)
		{
			vp.clear();
			return;
		}
	}
	vector<tuple<int, int, int>> key;
	for (int i = 0; i < vp.size(); i++)
	{
		int j = i;
		auto [l, r, g] = vp[i];
		while (j < vp.size())
		{
			auto [l1, r1, g1] = vp[j];
			if (g == g1)
			{
				r = r1;
				j++;
			}
			else
				break;
		}
		i = j - 1;
		key.emplace_back(l, r, g);
	}
	vp = key;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = 0;
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		int cur = x;
		reverse(vp.begin(), vp.end());
		for (auto& [l, r, g] : vp)
		{
			cur = g = gcd(g, cur);
		}
		reverse(vp.begin(), vp.end());
		vp.emplace_back(i, i, x);
		check(vp, i);
		if (vp.empty()) ans++;
		printf("%d%c", ans, " \n"[i == n]);
	}
	return 0;
}