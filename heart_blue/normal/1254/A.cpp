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
const int N = 1e2 + 10;
char str[N][N];
int getchar(int id)
{
	if (id < 10) return id + '0';
	else if (id < 36) return id - 10 + 'a';
	else return id - 36 + 'A';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int tot = 0;
		vector<pair<int, int>> ans;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				tot += str[i][j] == 'R';
				if (i & 1) ans.emplace_back(i, j);
				else ans.emplace_back(i, m - j + 1);
			}
		}
		int avg = tot / k;
		int r = tot % k;
		int cur = 0;
		int nex = avg;
		if (r) nex++, r--;
		int id = 0;
		for (auto& p : ans)
		{
			int x, y;
			tie(x, y) = p;
			cur += str[x][y] == 'R';
			if (cur > nex)
			{
				id++;
				nex += avg;
				if (r) nex++, r--;
			}
			str[x][y] = getchar(id);
		}
		while (++id < k)
		{
			int x, y;
			tie(x, y) = ans.back();
			ans.pop_back();
			str[x][y] = getchar(id);
		}
		for (int i = 1; i <= n; i++)
			puts(str[i] + 1);
	}
	return 0;

}