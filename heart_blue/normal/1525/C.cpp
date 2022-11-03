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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<int> vp[2];
		int n, len;
		scanf("%d%d", &n, &len);
		vector<pair<int, int>> key;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			key.emplace_back(a[i], i);
		}
		for (int i = 0; i < n; i++)
		{
			ans[i + 1] = -1;
			char c;
			scanf(" %c", &c);
			if (c == 'L')
				key[i].second *= -1;
		}
		sort(key.begin(), key.end());
		for (auto& [val, y] : key)
		{
			auto& v = vp[val & 1];
			if (v.empty() || y > 0)
				v.push_back(y);
			else
			{
				int x = v.back();
				int d = 0;
				y = abs(y);
				v.pop_back();
				if (x < 0) d = a[-x] + a[y];
				else d = a[y] - a[x];
				x = abs(x);
				ans[x] = ans[y] = d / 2;
			}
		}
		for (int o = 0; o < 2; o++)
		{
			auto& v = vp[o];
			while (v.size() > 1)
			{
				int y = v.back();
				v.pop_back();
				int x = v.back();
				v.pop_back();
				int d = 0;
				if (x < 0) d = 2 * len - a[y] + a[-x];
				else d = 2 * len - a[y] - a[x];
				x = abs(x);
				ans[x] = ans[y] = d / 2;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}