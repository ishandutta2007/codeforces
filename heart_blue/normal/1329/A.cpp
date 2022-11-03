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
int ans[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v;
	LL sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		sum += x;
		a[i] = x;
		if (i + x - 1 > n) puts("-1"), exit(0);
	}
	if (sum < n) puts("-1"), exit(0);
	for (int i = 1; i <= m; i++)
		ans[i] = i;
	int cur = n;
	for (int i = m; i >= 1; i--)
	{
		ans[i] = max(ans[i], cur - a[i] + 1);
		cur = ans[i] - 1;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	
	return 0;
}