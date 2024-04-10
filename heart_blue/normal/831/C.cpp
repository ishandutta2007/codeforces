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
int a[N];
map<int, int> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mc;
	int x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
	{
		cin >> x;
		mc[x] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int t = 0;
		int tot = 1;
		mc[x] = i;
		for (int j = i + 1; j <= n; j++)
		{
			t += a[j];
			if (mc.count(x + t) && mc[x + t] != i)
			{
				mc[x + t] = i;
				tot++;
			}
		}
		t = 0;
		for (int j = i; j > 1; j--)
		{
			t += a[j];
			if (mc.count(x - t) && mc[x - t] != i)
			{
				mc[x - t] = i;
				tot++;
			}
		}
		if (tot == k) ans[x - t - a[1]] = 1;
	}
	cout << ans.size() << endl;
	return 0;
}