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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
int a[20];
char s[20][N];
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
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		int maxv = -INF;
		vector<int> ans;
		for (int o = 0; o < (1 << n); o++)
		{
			int sum = 0;
			vector<pair<int, int>> v;
			for (int i = 0; i < m; i++)
			{
				v.emplace_back(0, i + 1);
			}
			for (int i = 0; i < n; i++)
			{
				int key = 1;
				if (o >> i & 1) key = -1;
				sum += -key * a[i];
				for (int j = 0; j < m; j++)
				{
					v[j].first += (s[i][j] - '0') * key;
				}
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < m; i++)
			{
				sum += v[i].first * (i + 1);
			}
			if (maxv < sum)
			{
				maxv = sum;
				ans.resize(m, 0);
				for (int i = 0; i < m; i++)
				{
					ans[v[i].second - 1] = i + 1;
				}
			}
		}
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}