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
const int N = 1e5 + 10;
int a[N];
vector<int> v[N];
int ans = 0;
void dfs(int x, int fa = 0)
{
	vector<int> key;
	key.push_back(x);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		if (a[y] == y)
			key.push_back(y);
	}
	if (key.size() >= 2)
	{
		ans += 2 + (key.size() - 2) * 2;
	}
	for (int i = 1; i < key.size(); i++)
	{
		swap(a[key[i - 1]], a[key[i]]);
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
		a[i] = i;
		if (i == n) break;
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	if (a[1] == 1)
		swap(a[1], a[v[1].front()]), ans += 2;
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}