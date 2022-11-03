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
map<LL, int> mc[N];
int dfs(int x, LL o)
{
	if (mc[x].count(o)) return mc[x][o];
	int &ret = mc[x][o] = 0;
	int flag[70];
	MEM(flag, 0);
	for (int i = 1; i <= x; i++)
	{
		if (o >> i & 1) continue;
		flag[dfs(x - i, 1 << i | o)] = 1;
	}
	for (int i = 0; i < 70; i++)
	{
		if (flag[i] == 0)
		{
			ret = i;
			break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		int x;
		cin >> x;
		ans ^= dfs(x, 0);
	}
	if (ans) puts("NO");
	else puts("YES");
	return 0;
}