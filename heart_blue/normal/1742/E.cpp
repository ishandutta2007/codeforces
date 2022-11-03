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
LL ans[N];
int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		n++;
		a[n] = INF;
		vector<pair<int, int>> qr;
		for (int i = 1; i <= q; i++)
		{
			int x;
			scanf("%d", &x);
			qr.emplace_back(x, i);
		}
		sort(qr.rbegin(), qr.rend());
		LL cur = 0;
		for (int i = 1; i <= n; i++)
		{
			while (!qr.empty() && qr.back().first < a[i])
			{
				ans[qr.back().second] = cur;
				qr.pop_back();
			}
			cur += a[i];
		}
		for (int i = 1; i <= q; i++)
			printf("%lld%c", ans[i], " \n"[i == q]);

	}
	return 0;
}