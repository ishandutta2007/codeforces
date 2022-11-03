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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 1;
const int N = 3e3;
int d[N][N];
int n;
int ans = INF;
void dfs(int u, int p, int sum = 0, int cur = 0)
{
	if (cur == n)
	{
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == p || i == u) continue;
		if (d[u][i] == -1) continue;
		dfs(i, u, sum+d[u][i], cur + 1);
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	MEM(d, -1);
	cin >> n;
	int a, b, c;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		d[b][a] = c;
		d[a][b] = 0;
	}
	dfs(1, -1);
	cout << ans << endl;
	return 0;
}