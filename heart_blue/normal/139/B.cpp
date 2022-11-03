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
const int N = 1e3 + 10;
int len[N];
int h[N];
int cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(cost, 0x3f);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b >> h[i];
		len[i] = (a + b) * 2;
	}
	int m;
	cin >> m;
	while (m--)
	{
		int we, hi, p;
		cin >> hi >> we >> p;
		for (int i = 1; i <= n; i++)
		{
			if (hi >= h[i])
			{
				int o = hi / h[i] * we;
				cost[i] = min(cost[i], (len[i] + o - 1) / o * p);
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans += cost[i];
	cout << ans << endl;
	return 0;
}