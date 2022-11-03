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
LL sum[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> ms1, ms2;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = max(0, a[i]) + sum[i - 1];
		if (!ms1.count(a[i])) ms1[a[i]] = i;
		ms2[a[i]] = i;
	}
	tuple<LL, int, int> ans = make_tuple(-INF * INF, 0, 0);
	for (auto& p : ms1)
	{
		int l = p.second;
		int r = ms2[p.first];
		if (l == r) continue;
		ans = max(ans, make_tuple(sum[r] - sum[l - 1] + 2 * min(p.first, 0), l, r));
	}
	LL res;
	int l, r;
	tie(res, l, r) = ans;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		if (i == l || i == r) continue;
		if (i < l || i > r || a[i] < 0)
			v.push_back(i);
	}
	cout << res << ' ' << v.size() << endl;
	for (auto& x : v) cout << x << ' ';
	return 0;
}