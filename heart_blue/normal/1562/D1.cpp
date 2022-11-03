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
const int N = 3e5 + 10;
map<int, vector<int>> mc[4];
int sum[N];
char str[N];
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
		scanf("%s", str + 1);
		sum[0] = sum[n + 1] = 0;
		for (int o = 0; o < 4; o++) mc[o].clear();
		for (int i = 1; i <= n; i++)
		{
			if (str[i] == '+') sum[i] = 1;
			else sum[i] = -1;
			if (i % 2 == 0) sum[i] *= -1;
			sum[i] += sum[i - 1];
		}
		for (int i = 1; i <= n; i++)
		{
			int o2 = (i & 1);
			int tot1 = sum[i - 1];
			int tot2 = sum[n] - sum[i];
			if (i & 1) tot2 = -tot2;
			for (int o1 = 0; o1 < 2; o1++)
			{
				int tot = tot1;
				if (o1 & 1) tot *= 1;
				else tot *= -1;
				if (o1 ^ o2) tot -= tot2;
				else tot += tot2;
				mc[o1 << 1 | o2][tot].emplace_back(i);
			}
		}
		for (int o = 0; o < 4; o++)
		{
			for (auto& p : mc[o])
			{
				auto& v = p.second;
				sort(v.begin(), v.end());
			}
		}
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			if (sum[r] - sum[l - 1] == 0)
			{
				puts("0");
				continue;
			}
			if ((r - l) % 2 == 1) puts("2");
			else puts("1");
		}
	}
	return 0;
}