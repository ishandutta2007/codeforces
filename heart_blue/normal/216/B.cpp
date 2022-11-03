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
const int N = 2e5 + 10;
vector<int> v[N];
int flag[N];
int cnt = 0;
bool dfs(int x, int fa = -1)
{
	if (flag[x] != -1)
	{
		if (fa == -1) return true;
		else return flag[x] != flag[fa];
	}
	if (fa == -1) flag[x] = 0;
	else flag[x] = flag[fa] ^ 1;
	cnt++;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		if (!dfs(y, x)) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(flag, -1);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		if (a > b) swap(a, b);
		if (!dfs(i))
		{
			a += cnt / 2;
			b += cnt / 2;
		}
		else
		{
			a += cnt - cnt / 2;
			b += cnt / 2;
		}
	}
	cout << n - min(a, b) * 2 << endl;
	return 0;
}