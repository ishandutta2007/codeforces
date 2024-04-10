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
const int N = 5e3 + 10;
int flag[N];
int sum1[N];
int sum2[N];
pair<int, int> p[N];
pair<int, int> combine(int l1, int r1, int l2, int r2)
{
	return make_pair(max(l1, l2), min(r1, r2));
}
pair<int, int> sub(int l1, int r1, int l2, int r2)
{
	if (l1 == l2)
	{
		return { r2 + 1,r1 };
	}
	if (r1 == r2)
	{
		return { l1,l2 - 1 };
	}
	return { l1,r1 };
}
int getans(pair<int,int> p, int sum[])
{
	int l, r;
	tie(l, r) = p;
	if (l > r) return 0;
	return sum[r] - sum[l - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		int l, r;
		cin >> l >> r;
		p[i] = { l,r };
		flag[l]++;
		flag[r + 1]--;
	}
	for (int i = 1; i <= n; i++) flag[i] += flag[i - 1];
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		sum1[i] = sum1[i - 1] + (flag[i] == 1);
		sum2[i] = sum2[i - 1] + (flag[i] == 2);
		tot += flag[i] > 0;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = i + 1; j <= k; j++)
		{
			int l1, r1;
			int l2, r2;
			tie(l1, r1) = p[i];
			tie(l2, r2) = p[j];
			auto pp = combine(l1, r1, l2, r2);
			if (pp.first > pp.second) pp = { 0,-1 };
			int cnt = getans(pp, sum2);
			auto p1 = sub(l1, r1, pp.first, pp.second);
			auto p2 = sub(l2, r2, pp.first, pp.second);
			cnt += getans(p1, sum1) + getans(p2, sum1);
			ans = max(ans, tot - cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}