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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int in[N], out[N];
int pos[N];
int cnt = 0;
vector<int> v[N];
void dfs(int x)
{
	in[x] = ++cnt;
	pos[cnt] = x;
	for (auto &y : v[x])
	{
		dfs(y);
	}
	out[x] = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1);
	while (q--)
	{
		int x, k;
		scanf("%d%d", &x, &k);
		int p = in[x] + k - 1;
		if (p > out[x]) puts("-1");
		else printf("%d\n", pos[p]);
	}
	return 0;
}