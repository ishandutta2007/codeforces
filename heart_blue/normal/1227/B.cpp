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
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		map<int, int> mc;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) mc[i] = 1;
		memset(ans, 0, sizeof(int) * (n + 1));
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] != a[i - 1])
			{
				if (a[i] < a[i - 1]) flag = 0;
				ans[i] = a[i];
				mc.erase(a[i]);
			}
		}
		for (int i = n; i >= 1; i--)
		{
			if (ans[i] == 0)
			{
				ans[i] = mc.rbegin()->first;
				mc.erase(mc.rbegin()->first);
			}
			if (ans[i] > a[i]) flag = 0;
		}
		if (flag == 0 || a[n] != n)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}