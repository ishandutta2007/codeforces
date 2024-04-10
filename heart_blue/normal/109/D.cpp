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
const int N = 1e5 + 10;
int pos[N];
pair<int, int> a[N], b[N];
bool check(int n)
{
	while (n)
	{
		int x = n % 10;
		n /= 10;
		if (x != 4 && x != 7) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<pair<int, int>, int> mc;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
		b[i] = a[i];
		mc[a[i]] = i;
	}
	if (is_sorted(a + 1, a + n + 1))
	{
		puts("0");
		return 0;
	}
	sort(a + 1, a + n + 1);

	pair<int, int> key = { -1,-1 };
	for (int i = 1; i <= n; i++)
	{
		if (check(a[i].first))
		{
			key = a[i];
		}
	}
	if (key.first == -1)
	{
		puts("-1");
		return 0;
	}
	int& k = mc[key];
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++)
	{
		if (i == mc[a[i]]) continue;
		int& s = mc[a[i]];
		int& t = mc[b[i]];
		if (t == s) continue;
		if (s == k) continue;
		if (k != t)
		{
			swap(b[k], b[t]);
			swap(k, t);
			ans.emplace_back(k, t);
		}
		if (k != s)
		{
			swap(b[k], b[s]);
			swap(k, s);
			ans.emplace_back(k, s);
		}
	}
	printf("%d\n", ans.size());
	for (auto [a, b] : ans)
		printf("%d %d\n", a, b);
	return 0;
}