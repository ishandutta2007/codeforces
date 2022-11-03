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
const int N = 2e5 + 10;
int a[N];
int ans[N];
vector<pair<int, int>> vp;
int lowbit(int x)
{
	return x&-x;
}

void add(int x)
{
	while (x < N)
	{
		a[x] ++;
		x += lowbit(x);
	}
}
int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += a[x];
		x -= lowbit(x);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	sort(vp.begin(), vp.end());
	for (auto &p : vp)
	{
		int o = p.second;
		int key1 = o, key2 = o;
		
		add(o);
		int s = sum(o);
		int l = 0, r = o;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (sum(mid) + 1 >= s) key1 = mid, r = mid - 1;
			else l = mid + 1;
		}
		key1 = min(key1 + 1, o);
		l = o, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (sum(mid) <= s) key2 = mid, l = mid + 1;
			else r = mid - 1;
		}
		
		ans[key2 - key1 + 1] = max(ans[key2 - key1 + 1], p.first);
	}
	for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}