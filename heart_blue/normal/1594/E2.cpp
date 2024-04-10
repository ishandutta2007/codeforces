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
const int N = 4e5 + 10;
const int M = 60 + 10;
LL dp[M][6];
map<string, int> ms;
map<LL, vector<int>> key;
map<LL, int> id;
void init()
{
	ms["white"] = 0;
	ms["yellow"] = 1;
	ms["green"] = 2;
	ms["blue"] = 3;
	ms["red"] = 4;
	ms["orange"] = 5;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 6; i++) dp[1][i] = 1;
	for (int o = 2; o <= 60; o++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if ((i ^ j) <= 1) continue;
				for (int k = 0; k < 6; k++)
				{
					if ((i ^ k) <= 1) continue;
					dp[o][i] = (dp[o][i] + dp[o - 1][j] * dp[o - 1][k]) % INF;
				}
			}
		}
	}
	init();
	int k;
	cin >> k;
	LL tot = (1LL << k) - 1;
	int n;
	cin >> n;
	priority_queue<LL> pq;
	map<LL, int> in;
	while (n--)
	{
		LL x;
		cin >> x;
		int o = 0;
		while ((x << o) <= tot) o++;
		string str;
		cin >> str;
		id[x] = ms[str];
		pq.emplace(x);
		in[x] = 1;
	}
	while (!pq.empty())
	{
		LL x = pq.top();
		pq.pop();
		if (x == 0) break;
		if (!in.count(x / 2))
			pq.emplace(x / 2), in[x / 2] = 1;
		int o = 0;
		while ((x << o) <= tot) o++;
		if (o == 1)
		{
			vector<int> v(6, 0);
			v[id[x]] = 1;
			key[x] = v;
			continue;
		}
		LL a = x * 2;
		LL b = x * 2 + 1;
		vector<int> v1, v2;
		if (key.count(a)) v1 = key[a];
		else v1 = vector<int>(dp[o - 1], dp[o - 1] + 6);
		if (key.count(b)) v2 = key[b];
		else v2 = vector<int>(dp[o - 1], dp[o - 1] + 6);
		int l = 0, r = 5;
		if (id.count(x))
			l = r = id[x];
		vector<int> v(6, 0);
		for (int i = l; i <= r; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if ((i ^ j) <= 1) continue;
				for (int k = 0; k < 6; k++)
				{
					if ((i ^ k) <= 1) continue;
					v[i] = (v[i] + 1LL * v1[j] * v2[k]) % INF;
				}
			}
		}
		key[x] = v;
	}
	auto& v = key[1];
	LL ans = 0;
	for (auto& x : v)
		ans += x;
	printf("%lld\n", ans % INF);
	return 0;
}