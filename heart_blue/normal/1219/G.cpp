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
vector<int> v1[N], v2[N];
LL tot[N];
LL solve4(vector<int> v[], int n)
{
	vector<LL> key;
	for (int i = 0; i < n; i++)
	{
		LL sum = 0;
		for (auto& x : v[i])
			sum += x;
		key.push_back(sum);
	}
	sort(key.rbegin(), key.rend());
	while (key.size() > 4) key.pop_back();
	LL ret = 0;
	for (auto& x : key)
		ret += x;
	return ret;
}
LL solve1(vector<int> v[], int n)
{
	MEM(tot, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			tot[j] += v[i][j];
		}
	}
	LL ret = 0;
	for (int i = 0; i < n; i++)
	{
		vector<LL> key;
		LL sum = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			sum += v[i][j];
			key.push_back(tot[j] - v[i][j]);
			sort(key.rbegin(), key.rend());
			while (key.size() > 3) key.pop_back();
		}
		for (auto& x : key)
			sum += x;
		ret = max(ret, sum);
	}
	return ret;
}
LL solve2(vector<int> v[], int n)
{
	if (n == 1) return 0;
	MEM(tot, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			tot[j] += v[i][j];
		}
	}
	LL ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			vector<LL> key;
			LL sum = 0;
			for (int k = 0; k < v[i].size(); k++)
			{
				sum += v[i][k];
				sum += v[j][k];
				key.push_back(tot[k] - v[i][k] - v[j][k]);
				sort(key.rbegin(), key.rend());
				while (key.size() > 2) key.pop_back();
			}
			for (auto& x : key)
				sum += x;
			ret = max(ret, sum);
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			v1[i].push_back(x);
			v2[j].push_back(x);
		}
	}
	LL ans = 0;
	ans = max(ans, solve4(v1, n));
	ans = max(ans, solve4(v2, n));
	ans = max(ans, solve1(v1, n));
	ans = max(ans, solve1(v2, m));
	if (n < m) ans = max(ans, solve2(v1, n));
	else ans = max(ans, solve2(v2, m));
	printf("%lld\n", ans);
	return 0;
}