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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int a[N];
vector<int> v[N];
pair<int, int> p[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i < N; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			v[a[i]].push_back(i);
		}
		int cnt = 500;
		vector<int> ans;
		int flag = 0;
		while (cnt--)
		{
			for (int i = 1; i < N; i++)
			{
				random_shuffle(v[i].begin(), v[i].end());
				for (int j = 0; j < v[i].size(); j++)
				{
					p[v[i][j]] = { i,j };
				}
			}
			ans.clear();
			for (int o = 1; o <= n; o++)
			{
				for (int i = 1; i + 2 <= n; i++)
				{
					while (p[i + 2] < p[i] || p[i + 2] < p[i + 1])
					{
						tie(p[i], p[i + 1], p[i + 2]) = make_tuple(p[i + 2], p[i], p[i + 1]);
						ans.push_back(i);
					}
				}
			}
			if (p[1] > p[2])
			{
				ans.clear();
				continue;
			}
			flag = 1;
			break;
		}
		if (flag == 0)
		{
			puts("-1");
			continue;
		}

		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}