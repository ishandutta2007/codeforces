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
struct Node
{
	int l, r, pos;
	bool operator < (const Node& node) const
	{
		if (l != node.l) return l < node.l;
		return r > node.r;
	}
};
Node vp[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &vp[i].l, &vp[i].r);
			vp[i].pos = i;
		}
		sort(vp + 1, vp + n + 1);
		fill(ans + 1, ans + n + 1, 2);
		int key = vp[1].r;
		for (int i = 1; i <= n; i++)
		{
			if (key >= vp[i].l)
			{
				ans[vp[i].pos] = 1;
				key = max(key, vp[i].r);
			}
			else break;
		}
		if (count(ans + 1, ans + n + 1, 1) == n)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}