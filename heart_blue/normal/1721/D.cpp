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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int b[N];
map<int, int> check(int v[], int n, int o, int ox)
{
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
		mc[(v[i] & o) ^ ox]++;
	return mc;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		int ans = 0;
		for (int o = 29; o >= 0; o--)
		{
			auto mc1 = check(a, n, 1 << o | ans, 0);
			auto mc2 = check(b, n, 1 << o | ans, 1 << o | ans);
			if (mc1 == mc2)
			{
				ans |= 1 << o;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}