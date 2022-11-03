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
map<int, int> ms;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		if (!ms.count(x)) ms[x] = 1;
		if (ms.count(x - 1)) ms[x] = max(ms[x], ms[x - 1] + 1);
	}
	pair<int, int> ans = { 0,0 };
	for (auto &p : ms)
	{
		ans = max(ans, { p.second,p.first });
	}
	cout << ans.first << endl;
	int cur = ans.second - ans.first + 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == cur)
		{
			cout << i << ' ';
			cur++;
		}
	}
	return 0;
}