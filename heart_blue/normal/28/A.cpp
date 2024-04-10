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
pair<int, int> a[N];
void solve(int n, int o)
{
	vector<int> ans;
	a[0] = a[n];
	a[n + 1] = a[1];
	for (int i = o; i <= n; i += 2)
	{
		int d = abs(a[i - 1].first - a[i + 1].first) + abs(a[i - 1].second - a[i + 1].second);
		if (v[d].empty())
		{
			return;
		}
		int x = v[d].back();
		int y = -1;
		if (o != 1) swap(x, y);
		ans.push_back(x);
		ans.push_back(y);
		v[d].pop_back();
	}
	puts("YES");
	for (auto& x : ans)
		printf("%d ", x);
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	solve(n, 1);
	solve(n, 2);
	puts("NO");
	return 0;
}