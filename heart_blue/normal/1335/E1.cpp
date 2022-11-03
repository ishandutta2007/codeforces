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
const int N = 1e5 + 10;
vector<int> v[N];
int l[N], r[N];
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
		for (int i = 1; i <= 200; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		int ans = 0;
		for (int i = 1; i <= 200; i++)
		{
			ans = max(ans, int(v[i].size()));
			if (v[i].size() <= 1) continue;
			for (int j = 1; j <= 200; j++)
			{
				l[j] = 0, r[j] = v[j].size();
				r[j]--;
			}
			int L = 0, R = v[i].size() - 1;
			while (L < R)
			{
				for (int j = 1; j <= 200; j++)
				{
					while (l[j] <= r[j] && v[j][l[j]] <= v[i][L]) l[j]++;
					while (r[j] >= l[j] && v[j][r[j]] >= v[i][R]) r[j]--;
					if (l[j] > r[j]) continue;
					ans = max(ans, (L + 1) * 2 + r[j] - l[j] + 1);
				}
				L++, R--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}