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
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		int q;
		scanf("%d", &q);
		vector<tuple<int, int, int>> qr;
		for (int i = 1; i <= q; i++)
		{
			int x, k;
			scanf("%d%d", &x, &k);
			qr.emplace_back(k, x, i);
		}
		sort(qr.begin(), qr.end());
		int flag = 0;
		int cur = 0;
		for (auto [k, x, pos] : qr)
		{
			while (cur < k && !flag)
			{
				cur++;
				map<int, int> mc;
				for (auto& val : v)
					mc[val]++;
				vector<int> v2;
				for (auto& x : v)
					v2.push_back(mc[x]);
				if (v2 == v) flag = 1;
				v = v2;
			}
			ans[pos] = v[x - 1];
		}
		for (int i = 1; i <= q; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}