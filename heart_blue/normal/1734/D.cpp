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
bool solve(int& n, int& k)
{
	reverse(a + 1, a + n + 1);
	k = n - k + 1;
	LL cur = 0;
	LL sum = 0;
	LL maxv = 0;
	vector<pair<LL, LL>> vp;
	for (int i = k - 1; i >= 1; i--)
	{
		sum += a[i];
		maxv = max(maxv, sum);
		if (sum < 0)
		{
			vp.emplace_back(cur, maxv);
			cur -= sum;
			maxv = cur;
			sum = 0;
		}
	}
	vp.emplace_back(cur, maxv);
	reverse(vp.begin(), vp.end());
	LL rtot = 0, ltot = 0;
	for (int i = k; i <= n; i++)
	{
		while (!vp.empty() && rtot >= vp.back().first)
		{
			ltot = max(vp.back().second - vp.back().first, ltot);
			vp.pop_back();
		}
		//if (vp.empty()) return true;
		if (ltot + rtot + a[i] < 0) return false;
		rtot += a[i];
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ks = 0;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		ks++;
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		/*if (ks == 11 && a[1] == -920734269)
		{
			printf("%d %d\n", n, k);
			for (int i = 1; i <= n; i++)
				printf("%d%c", a[i], " \n"[i == n]);
		}*/
		if (solve(n, k) || solve(n, k)) puts("YES");
		else puts("NO");
	}
	return 0;
}