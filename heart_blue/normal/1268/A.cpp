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
char a[N];
char b[N];
int n, k;
bool dfs(int cur = 1, int flag = 0)
{
	if (cur > n)
	{
		return true;
	}
	if (cur > k)
	{
		b[cur] = b[cur - k];
		if (flag || b[cur] >= a[cur])
		{
			return dfs(cur + 1, flag || b[cur] > a[cur]);
		}
		else return false;
	}
	for (int i = (cur == 1 ? '1' : '0'); i <= '9'; i++)
	{
		b[cur] = i;
		if (flag || b[cur] >= a[cur])
		{
			if (dfs(cur + 1, flag || b[cur] > a[cur]))
				return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", a + 1);
	b[n + 1] = 0;
	dfs();
	cout << n << endl;
	cout << b + 1 << endl;
	return 0;
}