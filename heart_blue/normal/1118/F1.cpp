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
const int N = 3e5 + 10;
int tot1 = 0, tot2 = 0;
int sum1[N], sum2[N];
int col[N];
vector<int> v[N];
int ans = 0;
void dfs(int x, int p = 0)
{
	sum1[x] = col[x] == 1;
	sum2[x] = col[x] == 2;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
		sum1[x] += sum1[y];
		sum2[x] += sum2[y];
	}
	if (1LL * sum1[x] * sum2[x] == 0 && (sum1[x] == tot1 || sum2[x] == tot2))
		ans++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
		if (col[i] == 1) tot1++;
		if (col[i] == 2) tot2++;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}