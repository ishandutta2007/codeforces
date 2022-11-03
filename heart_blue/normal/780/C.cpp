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
int col[N];
void dfs(int x, int fa = -1)
{
	int c1 = col[x], c2 = -1;
	if (fa != -1) c2 = col[fa];
	int cur = 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		while (cur == c1 || cur == c2) cur++;
		col[y] = cur++;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	col[1] = 1;
	dfs(1);
	int k = 0;
	for (int i = 1; i <= n; i++) k = max(k, col[i]);
	cout << k << endl;
	for (int i = 1; i <= n; i++) cout << col[i] << ' ';
	return 0;
}