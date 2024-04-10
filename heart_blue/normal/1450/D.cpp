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
const int N = 3e5 + 10;
int a[N];
int flag[N];
bool check(int n, int k)
{
	vector<int> v;
	deque<int> q;
	int maxv = n - k + 1;
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		while (!q.empty() && a[i] <= a[q.front()]) q.pop_front();
		q.push_front(i);
		while (!q.empty() && i - q.back() + 1 > k) q.pop_back();
		int x = a[q.back()];
		if (i >= k)
		{
			v.push_back(x);
			if (flag[x]) f = 0;
			if (x > maxv) f = 0;
			flag[x] = 1;
		}
	}
	for (auto& x : v)
		flag[x] = 0;
	return f;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (check(n, 1)) putchar('1');
		else putchar('0');
		int l = 2, r = n;
		int res = n + 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check(n, mid)) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		for (int i = 2; i < res; i++) putchar('0');
		for (int i = res; i <= n; i++) putchar('1');
		puts("");
	}
	return 0;
}