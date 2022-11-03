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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, r;
	cin >> n >> l >> r;
	vector<pair<pair<int, int>, int>> vp(n);
	for (int i = 0; i < n; i++)
	{
		vp[i].second = i + 1;
	}
	for (auto &p : vp) cin >> p.first.second;
	for (auto &p : vp) cin >> p.first.first;
	sort(vp.begin(), vp.end());
	int cur = -INF;
	for (auto &p : vp)
	{
		int a, c;
		tie(c, a) = p.first;
		int o = p.second;
		if (cur + a < l) cur = l - a;
		ans[o] = cur + a;
		cur++;
		if (ans[o] > r)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}