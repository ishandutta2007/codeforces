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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e6 + 10;
int a[25][N];
int b[25][N];
int n;

int check(int x, int len)
{
	int maxa = -INF;
	int minb = INF;
	int t = 0;
	while (len)
	{
		if (len & 1)
		{
			maxa = max(maxa, a[t][x]);
			minb = min(minb, b[t][x]);
			x += (1 << t);
		}
		len >>= 1;
		t++;
	}
	if (maxa > minb) return 1;
	else if (maxa == minb) return 0;
	else  return -1;
}
int getl(int x)
{
	int l = x;
	int r = n - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int tmp = check(x, mid - x + 1);
		if (tmp == 0) ans = mid, r = mid - 1;
		else if (tmp == -1) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int getr(int x)
{
	int l = x;
	int r = n - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int tmp = check(x, mid - x + 1);
		if (tmp == 0) ans = mid, l = mid + 1;
		else if (tmp == -1) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int solve(int x)
{
	int l = getl(x);
	int r = getr(x);
	if (l == -1 || r == -1) return 0;
	return r - l + 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0x8f);
	MEM(b, 0x7f);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[0][i];
	for (int i = 0; i < n; i++) cin >> b[0][i];
	for (int j = 0; (1 << j) <= n; j++)
	{
		for (int i = 0; i + (1 << j) < n; i++)
		{
			a[j + 1][i] = max(a[j][i], a[j][i + (1 << j)]);
			b[j + 1][i] = min(b[j][i], b[j][i + (1 << j)]);

		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		//cout << i << ' ' << solve(i) << endl;
		ans += solve(i);
	}
	cout << ans << endl;
	return 0;
}