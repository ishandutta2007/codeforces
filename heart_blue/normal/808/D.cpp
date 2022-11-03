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
LL tot = 0;
bool check(int n)
{
	reverse(a + 1, a + n + 1);
	map<LL, int> mc;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (tot == sum * 2)
		{
			return true;
		}
		if (tot - sum * 2 < 0)
		{
			if (abs(tot - 2 * sum) % 2 == 0)
			{
				if (mc.count(abs(tot - 2 * sum) / 2))
				{
					return true;
				}
			}
		}
		mc[a[i]] = 1;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], tot += a[i];
	if (tot & 1)
	{
		puts("NO");
		return 0;
	}
	if (check(n) || check(n)) puts("YES");
	else puts("NO");
	return 0;
}