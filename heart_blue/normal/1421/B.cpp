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
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		int a = str[0][1], b = str[1][0];
		int c = str[n - 2][n - 1], d = str[n - 1][n - 2];
		vector<pair<int, int>> ans;
		if (a == b)
		{
			if (c == a) ans.emplace_back(n - 2, n - 1);
			if (d == a) ans.emplace_back(n - 1, n - 2);
		}
		else if (c == d)
		{
			if (a == c) ans.emplace_back(0, 1);
			if (b == c) ans.emplace_back(1, 0);
		}
		else
		{
			if (a == '0') ans.emplace_back(0, 1);
			if (b == '0') ans.emplace_back(1, 0);
			if (c == '1') ans.emplace_back(n - 2, n - 1);
			if (d == '1') ans.emplace_back(n - 1, n - 2);
		}
		printf("%d\n", ans.size());
		for (auto& p : ans)
			printf("%d %d\n", p.first + 1, p.second + 1);
	}
	return 0;
}