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
const int N = 1e5 + 10;
int n, m;
int a[N];
int cost[N];
int nxt[N];
int cur[N];
bool check(int x)
{
	int tot = 0;
	int cnt = 0;
	for (int i = 1; i <= x; i++)
	{
		if (a[i] == 0)
		{
			tot++;
			continue;
		}
		if (nxt[i] <= x)
		{
			tot++;
			continue;
		}
		if (cost[a[i]] > tot) return false;
		tot -= cost[a[i]];
		cnt++;
	}
	return cnt == m;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> cost[i];
	MEM(cur, 0x3f);
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 0) continue;
		nxt[i] = cur[a[i]];
		cur[a[i]] = i;
	}

	int ans = -1;
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}