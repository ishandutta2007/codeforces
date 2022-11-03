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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s;
	cin >> n >> s;
	int rest = 0;
	int zero = 0;
	int corr = 0;
	int ans = INF;
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (s == i)
		{
			if (x != 0) flag = 1;
			continue;
		}
		rest++;
		if (x != 0) a[x]++;
	}
	if (n == 1) ans = flag;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0) zero++;
		rest -= a[i];
		corr += max(0, a[i] - 1);
		if (zero > rest + corr)
		{
			break;
		}
		ans = min(ans, max(rest, zero));
	}
	cout << ans + flag << endl;
	return 0;
}