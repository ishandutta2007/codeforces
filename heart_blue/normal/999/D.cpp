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
int cnt[N];
int a[N];
int n, m;
int getnext(int x, int r)
{
	if (x%m < r) x += r - x % m;
	else
	{
		x += m - x % m;
		x += r;
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		cnt[x%m]++;
	}
	LL ans = 0;
	set<int> s;
	for (int i = 0; i < m; i++)
	{
		if (cnt[i] >= n / m) continue;
		s.insert(i);
	}
	for (int i = 0; i <= n * 10; i++)
	{
		int x = i % m;
		int y = (i + 1) % m;
		if (cnt[x] > n / m)
		{
			LL o = cnt[x] - n / m;
			cnt[x] = n / m;
			ans += o;
			cnt[y] += o;
		}
	}
	cout << ans << endl;
	MEM(cnt, 0);
	for (int i = 0; i < n; i++) cnt[a[i] % m]++;
	for (int i = 0; i < n; i++)
	{
		int x = a[i] % m;
		if (cnt[x] > n / m)
		{

			auto iter1 = s.upper_bound(x);
			int r;
			if (iter1 != s.end())
			{
				r = *iter1;
				a[i] = getnext(a[i], r);
				cnt[x]--;
				cnt[r]++;
				if (cnt[r] == n / m) s.erase(r);
				continue;
			}
			iter1 = s.upper_bound(-1);
			if (iter1 != s.end())
			{
				r = *iter1;
				a[i] = getnext(a[i], r);
				cnt[x]--;
				cnt[r]++;
				if (cnt[r] == n / m) s.erase(r);
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}