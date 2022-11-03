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
LL ans0[40];
LL ans1[40];
pair<LL, int> a[N];
map<LL, vector<int>> mc;
int b[N];
void solve(int l, int r, int o)
{
	int cnt0 = 0;
	int cnt1 = 0;
	LL res0 = 0;
	LL res1 = 0;
	for (int i = l; i <= r; i++)
	{
		int x = b[i];
		if (x == 0)
		{
			cnt0++;
			res0 += cnt1;
		}
		else
		{
			cnt1++;
			res1 += cnt0;
		}
	}
	ans0[o] += res0;
	ans1[o] += res1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}
	LL cur = 1ULL << 31;
	for (int o = 30; o >= 0; o--)
	{
		sort(a + 1, a + n + 1, [&cur](const pair<LL,int>& x, const pair<LL,int>& y)->bool
			{
				return make_pair((x.first & cur), x.second) < make_pair((y.first & cur), y.second);
			});
		for (int i = 1; i <= n; i++)
		{
			b[i] = a[i].first >> o & 1;
		}
		for (int i = 1; i <= n; i++)
		{
			int j = i;
			while (j <= n && (a[j].first & cur) == (a[i].first & cur))
			{
				j++;
			}
			solve(i, j - 1, o);
			i = j - 1;
		}
		cur |= 1LL << o;
	}
	LL res = 0;
	LL key = 0;
	for (int i = 0; i < 40; i++)
	{
		res += min(ans0[i], ans1[i]);
		if (ans1[i] < ans0[i])
			key |= 1LL << i;
	}
	printf("%lld %lld\n", res, key);
	return 0;
}