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
const int N = 1e3 + 10;
pair<int, int> key2[N], key3[N];
pair<int, int> pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		pair<int, int> k = { -1,-1 };
		fill(key2, key2 + N, k);
		fill(key3, key3 + N, k);
		fill(pre, pre + N, k);
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; j++)
			{
				if (j + 1 < m)
				{
					key2[stoi(str.substr(j, 2))] = { i,j };
				}
				if (j + 2 < m)
				{
					key3[stoi(str.substr(j, 3))] = { i,j };
				}
			}
		}
		pre[0] = { 0,0 };
		string str;
		cin >> str;
		str = "0" + str;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 2; j <= 3 && i - j >= 0; j++)
			{
				if (pre[i - j] == k) continue;
				int x = stoi(str.substr(i - j + 1, j));
				if (j == 2 && key2[x] != k)
				{
					pre[i] = { j,x };
				}
				if (j == 3 && key3[x] != k)
				{
					pre[i] = { j,x };
				}
			}
		}
		if (pre[m]== k)
		{
			puts("-1");
			continue;
		}
		vector<tuple<int, int, int>> ans;
		int cur = m;
		while (cur > 0)
		{
			auto [len, id] = pre[cur];
			int l, pos;
			if (len == 2) tie(pos, l) = key2[id];
			else tie(pos, l) = key3[id];
			ans.emplace_back(pos, l, l + len - 1);
			cur -= len;
		}
		reverse(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (auto [pos, l, r] : ans)
			printf("%d %d %d\n", l + 1, r + 1, pos + 1);
	}
	return 0;
}