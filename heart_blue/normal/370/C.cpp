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
int a[N];
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	priority_queue<pair<int, int>> pq;
	int n;
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sz[a[i]]++;
	}
	vector<pair<int, int>> vp;
	int maxv = 0;
	for (int i = 1; i <= m; i++)
	{
		maxv = max(maxv, sz[i]);
		vp.emplace_back(sz[i], i);
	}
	int cur = 1;
	sort(vp.begin(), vp.end());
	while (!vp.empty())
	{
		auto p = vp.back();
		vp.pop_back();
		while (p.first--)
			a[cur++] = p.second;
	}
	int ans = 0;
	int l = 1;
	int r = l + maxv;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++)
	{
		if (r > n) r -= n;
		if (a[l] != a[r])
			ans++;
		v.emplace_back(a[l], a[r]);
		l++, r++;
	}
	printf("%d\n", ans);
	for (auto& p : v)
		printf("%d %d\n", p.first, p.second);
	return 0;
}