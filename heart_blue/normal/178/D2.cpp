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
const int N = 5e2 + 10;
int a[4][4];
void check(int n, int key)
{
	int sum1[4] = { 0,0,0,0 };
	int sum2[4] = { 0,0,0,0 };
	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum1[i] += a[i][j];
			sum2[j] += a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (sum1[i] != key) return;
		if (sum2[i] != key) return;
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) x += a[i][i], y += a[i][n - i - 1];
	if (x != key) return;
	if (y != key) return;
	cout << key << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d%c", a[i][j], " \n"[j == n - 1]);
		}
	}
	exit(0);
}
void change(vector<int>& v, int n)
{
	int o = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = v[o++];
		}
	}
}
void solve3(int n)
{
	vector<int> v(n * n);
	LL tot = 0;
	for (auto& x : v) cin >> x, tot += x;
	tot /= n;
	sort(v.begin(), v.end());
	do
	{
		change(v, n);
		check(n, tot);
	} while (next_permutation(v.begin(), v.end()));
}
inline void del(map<int, int>& mc, int x)
{
	if (mc[x]-- == 1) mc.erase(x);
}
inline void add(map<int, int>& mc, int x)
{
	mc[x]++;
}
vector<pair<int, int>> vp = { {0,2},{1,2},{2,2},{2,1} };
vector<vector<int>> qr[10];
/*
1 1 1 1
1 1 1 1
0 0 1 0
0 0 0 0
*/
void init()
{
	qr[0].emplace_back(vector<int>{0, 3, 0, 0, 0, 1, 0, 2});
	qr[1].emplace_back(vector<int>{1, 3, 1, 0, 1, 1, 1, 2});
	qr[2].emplace_back(vector<int>{3, 2, 0, 2, 1, 2, 2, 2});
	qr[2].emplace_back(vector<int>{3, 3, 0, 0, 1, 1, 2, 2});
	qr[2].emplace_back(vector<int>{2, 3, 0, 3, 1, 3, 3, 3});
	qr[3].emplace_back(vector<int>{2, 0, 2, 1, 2, 2, 2, 3});
	qr[3].emplace_back(vector<int>{3, 0, 0, 0, 1, 0, 2, 0});
	qr[3].emplace_back(vector<int>{3, 1, 0, 1, 1, 1, 2, 1});
}
bool check(vector<pair<int, int>>& vp, int cur, int key)
{
	map<int, int> mc;
	for (auto& p : vp)
		if (p.second)
			mc.insert(p);
	for (auto& v : qr[cur])
	{
		int rest = key;
		for (int i = 2; i < v.size(); i += 2)
		{
			rest -= a[v[i]][v[i + 1]];
		}
		if (!mc.count(rest)) return false;
		del(mc, rest);
		a[v[0]][v[1]] = rest;
	}
	vp.clear();
	for (auto& p : mc)
		vp.push_back(p);
	return true;
}
void dfs(int cur, vector<pair<int, int>>& vp, int key)
{
	if (cur == 4)
	{
		check(4, key);
		return;
	}
	int x, y;
	tie(x, y) = ::vp[cur];
	for (int i = 0; i < vp.size(); i++)
	{
		if (vp[i].second == 0) continue;
		auto vv = vp;
		vv[i].second--;
		a[x][y] = vv[i].first;
		if (!check(vv, cur, key)) continue;
		dfs(cur + 1, vv, key);
	}
}
void solve4(vector<int> v, map<int, int> mc, int tot)
{
	for (auto& x : v)
		del(mc, x);
	vector<pair<int, int>> vp;
	for (auto& p : mc)
		vp.push_back(p);
	sort(v.begin(), v.end());
	do
	{
		change(v, 2);
		dfs(0, vp, tot);
	} while (next_permutation(v.begin(), v.end()));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 3) solve3(n);
	init();
	vector<int> v(n * n);
	LL tot = 0;
	map<int, int> mc;
	for (auto& x : v) cin >> x, tot += x, mc[x]++;
	sort(v.begin(), v.end());
	for (int i = 1; i < n * n; i++)
	{
		for (int j = i + 1; j < n * n; j++)
		{
			for (int k = j + 1; k < n * n; k++)
			{
				vector<int> tmp = { v[0],v[i],v[j],v[k] };
				//cout << i << ' ' << j << ' ' << k << endl;
				solve4(tmp, mc, tot / 4);
			}
		}
	}
	return 0;
}