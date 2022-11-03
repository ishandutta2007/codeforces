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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 4e5 + 10;
int ans[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(ans, 0);
	for (int i = 0; i < m; i++) cin >> a[i];
	int flag = 1;
	map<int, int> mc;
	for (int i = 1; i <= n; i++) mc[i] = 1;
	for (int i = 0; i + 1 < m; i++)
	{
		if (ans[a[i]])
		{
			if ((a[i + 1] - a[i] + n) % n != ans[a[i]] % n)
			{
				flag = 0;
				break;
			}
		}
		else
		{
			ans[a[i]] = (a[i + 1] - a[i] + n) % n;
			if (ans[a[i]] == 0) ans[a[i]] = n;
			if (!mc.count(ans[a[i]]))
			{
				flag = 0;
				break;
			}
			mc.erase(ans[a[i]]);
		}
	}
	if (flag == 0) puts("-1");
	else for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0) ans[i] = mc.begin()->first, mc.erase(ans[i]);
		cout << ans[i] << ' ';
	}
	return 0;
}