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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];
int ans[N];
int maxv = 0;
void dfs(int q)
{
	if (q == 0) return;
	int op;
	int x, y;
	cin >> op;
	cin >> x;
	if (op == 1) cin >> y;
	dfs(q - 1);
	if (op == 1)
	{
		if (flag[x]) return;
		ans[x] = max(y, maxv);
		flag[x] = 1;
	}
	else maxv = max(maxv, x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> ans[i];
	int q;
	cin >> q;
	dfs(q);
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
			ans[i] = max(ans[i], maxv);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	return 0;
}