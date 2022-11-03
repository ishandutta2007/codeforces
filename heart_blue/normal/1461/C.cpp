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
int a[N];
double p[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++) p[i] = 1;
		for (int i = 0; i <= n; i++) flag[i] = 1;
		while (m--)
		{
			int r;
			double pro;
			cin >> r >> pro;
			p[r] *= (1 - pro);
			flag[r] = 1;
		}
		double ans = 0;
		int o = n + 1;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] == i) o = i;
			else break;
		}
		if (o == 1)
		{
			puts("1");
			continue;
		}
		double pre = 1;
		for (int i = o - 1; i <= n; i++)
		{
			if (flag[i] == 0) continue;
			ans += pre * (1 - p[i]);
			pre *= p[i];
		}
		printf("%.15f\n", ans);
	}
	return 0;
}