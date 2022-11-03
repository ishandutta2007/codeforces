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
const int N = 3e2 + 10;
int a[N];
int maxv[N];
int cnt[N];
int ans[N];
int n;
void solve(int o)
{
	for (int i = 1; i <= o; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x = a[j];
			for (int k = 1; k <= x; k++)
			{
				maxv[x] = max(maxv[x], maxv[k]);
			}
			maxv[x]++;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> n >> t;
	MEM(cnt, 0);
	MEM(ans, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	int o1 = min(100, t);
	int o3 = min(100, t - o1);
	int o2 = t - o1 - o3;
	MEM(maxv, 0);
	solve(o1);
	for (int i = 1; i <= n; i++)
	{
		ans[a[i]] = maxv[a[i]] + o2 * cnt[a[i]];
	}
	memcpy(maxv, ans, sizeof(ans));
	solve(o3);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, maxv[a[i]]);
	}
	cout << res << endl;
	return 0;
}