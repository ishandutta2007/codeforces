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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
const int M = 1e6 + 10;
int a[N][N];
char str[N];
int b[M];
pair<int, int> minv[M];
void floyd(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = str[j] - '0';
			if (a[i][j] == 0) a[i][j] = INF;
		}
	}
	floyd(n);
	int m;
	MEM(minv, 0x3f);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
	}
	minv[1] = { 1,0 };
	for (int i = 1; i <= m; i++)
	{
		int x = b[i];
		for (int j = 1; j <= n; j++)
		{
			int o = i + a[x][j];
			if (o <= m && b[o] == j && j != x)
			{
				minv[o] = min(minv[o], make_pair(minv[i].first + 1, i));
			}
		}
	}
	vector<int> ans;
	int cur = m;
	while (cur)
	{
		ans.push_back(b[cur]);
		cur = minv[cur].second;
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto &x : ans)
		printf("%d ", x);
	return 0;
}