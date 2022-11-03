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
const int N = 2e5 + 20;
int a[N];
bool check(int i)
{
	return a[i] > a[i - 1] && a[i] > a[i + 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		a[0] = INF;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[n + 1] = INF;
		pair<int, int> ans = { -1,-1 };
		int ptr = 1;
		int sum = 0;
		for (int i = 2; i <= n; i++)
		{
			while (ptr <= n && ptr - i + 1 <= k - 2) sum += check(ptr++);
			ans = max(ans, make_pair(sum + 1, -i));
			sum -= check(i);
		}
		printf("%d %d\n", ans.first, -ans.second - 1);
	}
	return 0;
}