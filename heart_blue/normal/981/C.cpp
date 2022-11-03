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
int deg[N];
int fa[N];

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
		deg[x]++;
		deg[y]++;
	}
	int key = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] >= 3) cnt++;
		if (deg[key] < deg[i]) key = i;
	}
	if (cnt > 1)
	{
		puts("No");
		return 0;
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (i == key) continue;
		if (deg[i] == 1) ans.push_back(i);
	}
	puts("Yes");
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%d %d\n", key, x);
	return 0;
}