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
const int N = 2e2 + 10;
char str[N][N];
void solve(vector<vector<int>>& vp, int n, int m)
{
	vector<tuple<int, int, int>> vv;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			vv.emplace_back(str[n - i][m - j] - '0', n - i, m - j);
		}
	}
	while (1)
	{
		sort(vv.rbegin(), vv.rend());
		int cnt = 0;
		for (auto& p : vv)
			cnt += get<0>(p);
		if (cnt == 0) break;
		if (cnt == 2) swap(vv[0], vv[3]);
		vector<int> v;
		for (int i = 0; i < 3; i++)
		{
			int o, x, y;
			tie(o, x, y) = vv[i];
			o ^= 1;
			v.push_back(x);
			v.push_back(y);
			vv[i] = make_tuple(o, x, y);
		}
		vp.push_back(v);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	MEM(str, '0');
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
		}
		vector<vector<int>> vp;
		for (int i = 1; i + 2 <= n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				vector<int> v;
				for (int o = 0; o < 2; o++)
				{
					if (str[i][j + o] == '1')
					{
						v.push_back(i);
						v.push_back(j + o);
						str[i][j + o] = '0';
					}
				}
				if (v.empty()) continue;
				for (int o = 0; o < 2 && v.size() < 6; o++)
				{
					v.push_back(i + 1);
					v.push_back(j + o);
					str[i + 1][j + o] ^= 1;
				}
				vp.push_back(v);
			}
		}
		for (int i = 1; i < m; i++)
		{
			vector<int> v;
			for (int o = 0; o < 2; o++)
			{
				if (str[n - o][i] == '1')
				{
					str[n - o][i] = '0';
					v.push_back(n - o);
					v.push_back(i);
				}
			}
			if (v.empty()) continue;
			for (int o = 0; o < 2 && v.size() < 6; o++)
			{
				v.push_back(n - o);
				v.push_back(i + 1);
				str[n - o][i + 1] ^= 1;
			}
			vp.push_back(v);
		}
		solve(vp, n, m);
		printf("%d\n", vp.size());
		for (auto& v : vp)
		{
			for (auto& x : v)
				printf("%d ", x);
			puts("");
		}
	}
	return 0;
}