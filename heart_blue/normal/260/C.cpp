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
LL a[N];
LL lminv[N];
LL rminv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	int offset = n - x;
	for (int i = 1; i <= n; i++)
	{
		int p = i + offset;
		if (p > n) p -= n;
		cin >> a[p];
	}
	a[0] = lminv[0] = INF;
	a[n + 1] = rminv[n + 1] = INF;
	for (int i = 1; i <= n; i++) lminv[i] = min(a[i], lminv[i - 1]);
	for (int i = n; i > 0; i--) rminv[i] = min(a[i], rminv[i + 1]);
	int key = 1;
	if (lminv[n] >= a[n] - 1) key = n;
	for (int i = 1; i < n; i++)
	{
		if (rminv[i + 1] <= a[i]) continue;
		if (lminv[i] < a[i]) continue;
		key = i;
	}
	int o = a[key];
	for (int i = 1; i <= key; i++)
	{
		a[i] -= o;
		a[key] += o;
	}
	for (int i = key + 1; i <= n; i++)
	{
		a[i] -= o + 1;
		a[key] += o + 1;
	}
	int cur = 1 + n - x;
	for (int i = 1; i <= n; i++)
	{
		cout << a[cur++] << ' ';
		if (cur > n) cur = 1;
	}
	return 0;
}