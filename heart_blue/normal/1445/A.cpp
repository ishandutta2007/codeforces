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
const int N = 2e3 + 10;
void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v1(n), v2(n);
	for (auto& x : v1) scanf("%d", &x);
	for (auto& x : v2) scanf("%d", &x);
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());
	for (auto& x : v1)
	{
		int flag = 0;
		for (auto& y : v2)
		{
			if (y == -1) continue;
			if (x + y <= k)
			{
				y = -1;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			puts("No");
			return;
		}
	}
	puts("Yes");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		solve();
	}
	return 0;
}