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
const int N = 1e5 + 10;
int sum1[N];
int sum2[N];
int v[N];
int solve(int l, int r, int x, int sum[])
{
	int o = sum[l - 1];
	int ret = r + 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (sum[mid] - o >= x) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(sum1, 0);
	MEM(sum2, 0);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
		if (x == 1) sum1[i] = 1;
		else sum2[i] = 1;
		sum1[i] += sum1[i - 1];
		sum2[i] += sum2[i - 1];
	}
	vector<pair<int, int>> vp;
	for (int k = 1; k <= n; k++)
	{
		int cur = 1;
		int cnt1 = 0;
		int cnt2 = 0;
		int flag = 1;
		int last = 1;
		while (cur <= n)
		{
			int a = solve(cur, n, k, sum1);
			int b = solve(cur, n, k, sum2);
			cur = min(a, b) + 1;
			if (a == b)
			{
				flag = 0;
			}
			if (a < b) cnt1++, last = 1;
			if (a > b) cnt2++, last = 2;
		}
		if (flag == 0 || cnt1 == cnt2) continue;
		if (cnt1 > cnt2 && last == 2) continue;
		if (cnt1 < cnt2 && last == 1) continue;
		vp.push_back({ max(cnt1,cnt2),k });
	}
	sort(vp.begin(), vp.end());
	printf("%d\n", vp.size());
	for (auto &p : vp)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}