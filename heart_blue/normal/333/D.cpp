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
int a[N][N];
vector<int> v[N];
int flag[N][N];
int n, m;
bool check(int x)
{
	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] >= x) 
				v[i].push_back(j);
		}
	}
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int k = j + 1; k < v[i].size(); k++)
			{
				int x = v[i][j];
				int y = v[i][k];
				if (flag[x][y]) return true;
				flag[x][y] = 1;
			}
		}
	}
	return false;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int l = 0, r = INF;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}