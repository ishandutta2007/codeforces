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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	vector<int> v;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		cin >> sz;
		int minv = INF, maxv = 0;
		int flag = 0;
		int premin = INF;
		while (sz--)
		{
			int x;
			cin >> x;
			if (x > premin) flag = 1;
			premin = min(premin, x);
			minv = min(minv, x);
			maxv = max(maxv, x);
		}
		if (flag)
		{
			cnt++;
			continue;
		}
		vp.emplace_back(minv, maxv);
		v.push_back(maxv);
	}
	sort(v.begin(), v.end());
	LL ans = 0;
	ans = 1LL*cnt * n * 2 - 1LL*cnt * cnt;
	for (auto& p : vp)
	{
		int l, r;
		tie(l, r) = p;
		ans += v.end() - upper_bound(v.begin(), v.end(), l);
	}
	cout << ans << '\n';
	return 0;
}