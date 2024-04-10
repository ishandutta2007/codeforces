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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[N];
int b[N];
vector<pair<int,int>> vp;
vector<int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	double tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		tot += a[i];
		if (b[i] == 1) vp.push_back({ a[i],i });
	}
	sort(vp.rbegin(), vp.rend());
	int o = min(int(vp.size()), k);
	for (int i = 0; i < o; i++)
	{
		ans[i].push_back(vp[i].second);
	}
	for (int i = o; i < vp.size(); i++)
	{
		ans[o - 1].push_back(vp[i].second);
	}
	int l = vp.size();
	int r = k - 1;
	l = min(l, r);
	int p = l;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 1) continue;
		ans[p++].push_back(i);
		if (p > r) p = l;
	}
	for (int i = 0; i < o; i++)
	{
		sort(ans[i].begin(), ans[i].end(), [](int x, int y) -> bool
		{
			return a[x] < a[y];
		});
		tot -= a[ans[i].front()] / 2.0;
	}
	printf("%.1f\n", tot);
	for (int i = 0; i < k; i++)
	{
		cout << ans[i].size();
		for (auto &x : ans[i]) cout << ' ' << x;
		cout << '\n';
	}
	return 0;
}