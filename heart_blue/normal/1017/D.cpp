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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int w[N];
int cnt[N];
char str[N];
int ans[N];
vector<pair<int, int>> v[N];
int check(int n)
{
	int o = 0;
	for (int j = n - 1; j >= 0; j--)
	{
		o <<= 1;
		o |= str[j] - '0';
	}
	return o;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	int mask = (1 << n) - 1;
	for (int i = 0; i < n; i++) scanf("%d", &w[1 << i]);
	for (int i = 1; i <= mask; i++)
	{
		if (i == (i&-i)) continue;
		w[i] = w[i&-i] + w[i - (i&-i)];
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", str);
		int o = check(n);
		cnt[o]++;
	}
	for (int i = 0; i <= mask; i++)
	{
		for (int j = 0; j <= mask; j++)
		{
			v[i].push_back({ w[i^j^mask], cnt[j] });
		}
		sort(v[i].begin(), v[i].end());
		for (int j = 1; j < v[i].size(); j++)
		{
			v[i][j].second += v[i][j - 1].second;
		}
	}
	while (q--)
	{
		int tot;
		scanf("%s%d", str, &tot);
		int o = check(n);
		int pos = upper_bound(v[o].begin(), v[o].end(), make_pair(tot, int(INF))) - v[o].begin();
		if (pos == 0) puts("0");
		else
		{
			pos--;
			printf("%d\n", v[o][pos].second);
		}
	}
	return 0;
}