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
const int N = 1e5 + 10;
int a[N];
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
		vector<pair<int, int>> vp(m);
		map<int, int> mc1, mc2;
		for (auto &[x, y] : vp)
			scanf("%d%d", &x, &y), mc1[x]++, mc2[y]++;
		int ok = 0;
		for (auto [x, y] : vp)
		{
			mc1[x]--;
			mc2[y]--;
			int flag = 0;
			for (auto& p : mc1)
			{
				if (p.second > 1) flag = 1;
			}
			for (auto& p : mc2)
			{
				if (p.second > 1) flag = 1;
			}
			if (flag)
			{
				mc1[x]++;
				mc2[y]++;
				continue;
			}
			int kx = -1, ky = -1;
			for (int i = 1; i <= n; i++)
			{
				if (i == x || mc1[i] > 0) continue;
				kx = i;
			}
			for (int i = 1; i <= n; i++)
			{
				if (i == y || mc2[i] > 0) continue;
				ky = i;
			}
			if (kx == -1 || ky == -1)
			{
				mc1[x]++;
				mc2[y]++;
				continue;
			}
			ok = 1;
			break;
		}
		if (ok) puts("YES");
		else puts("NO");

	}
	return 0;
}