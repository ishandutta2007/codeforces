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
const int N = 1e3 + 10;
tuple<int, int, int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) ans[i] = { INF,0, 0 };
	for (int o = 1; o <= m; o++)
	{
		int l, r, t, cost;
		cin >> l >> r >> t >> cost;
		for (int i = l; i <= r; i++)
		{
			ans[i] = min(ans[i], { t,o, -cost });
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res -= get<2>(ans[i]);
	cout << res << endl;
	return 0;
}