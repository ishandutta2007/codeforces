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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int cnt[N];
int a[N];
pair<int, int> minv[20][N];
int fa[20][N];
void init()
{
	for (int i = 1; i < N; i++)
		cnt[i] = cnt[i >> 1] + 1;
}
//void add(int l, int r, int val)
//{
//	int o = cnt[r - l + 1] - 1;
//	r -= (1 << o) - 1;
//	minv[o][l] = min(minv[o][l], val);
//	minv[o][r] = min(minv[o][r], val);
//}
int query2(int l, int r)
{
	int o = cnt[r - l + 1] - 1;
	r -= (1 << o) - 1;
	return min(minv[o][l], minv[o][r]).second;
}
int query1(int l, int r)
{
	int o = cnt[r - l + 1] - 1;
	r -= (1 << o) - 1;
	return min(minv[o][l], minv[o][r]).first;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	init();
	MEM(minv, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 2; i <= n * 2; i++)
	{
		a[i] = min(a[i], n - 1);
		minv[0][i] = make_pair(max(0, i - a[i]), i);
	}
	minv[0][1] = { 0,0 };
	for (int o = 1; o < 20; o++)
	{
		int offset = 1 << (o - 1);
		for (int i = 1; i + (1 << o) - 1 <= n * 2; i++)
		{
			minv[o][i] = min(minv[o - 1][i], minv[o - 1][i + offset]);
		}
	}
	fa[0][1] = 0;
	for (int i = 2; i <= 2 * n; i++)
	{
		fa[0][i] = query2(max(1, i - a[i]), i - 1);
	}
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= 2 * n; i++)
		{
			fa[o][i] = fa[o - 1][fa[o - 1][i]];
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = i + n - 1;
		int sum = 0;
		for (int o = 19; o >= 0; o--)
		{
			if (fa[o][x] > i)
				x = fa[o][x], sum += 1 << o;
		}
		if (sum > 0)
		{
			sum--;
			int l, r;
			l = r = i + n - 1;
			for (int o = 0; sum >> o; o++)
			{
				if (sum >> o & 1)
					l = fa[o][l];
			}
			if (query1(l, r) > i) sum++;
		}
		sum++;
		//cout << i << ' ' << sum << endl;
		ans += sum;
	}
	printf("%lld\n", ans);

	return 0;
}