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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
char a[N][N];
int vis[N];
int n;
void dfs(int x, int fa = -1)
{
	if (vis[x]) return;
	vis[x] = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[x][i] == '0') continue;
		if (fa != -1 && a[i][fa] == '1')
		{
			cout << fa + 1 << ' ' << x + 1 << ' ' << i + 1 << endl;
			exit(0);
		}
		dfs(i, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", a[i]);
	for (int i = 0; i < n; i++) dfs(i);
	puts("-1");
	return 0;
}