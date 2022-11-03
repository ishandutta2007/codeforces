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
int sz[N];
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
		fill(sz + 1, sz + n + 1, 0);
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			sz[x]++;
		}
		vector<int> v(sz + 1, sz + n + 1);
		v.push_back(1);
		sort(v.rbegin(), v.rend());
		while (v.back() == 0)
			v.pop_back();
		int l = v.size(), r = n;
		int ans = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int cost = v.size();
			for (int i = 0; i < v.size(); i++)
			{
				cost += max(0, v[i] - (mid - i));
			}
			if (cost <= mid) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}