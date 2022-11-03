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
const int N = 2e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mc[x]++;
		sum += x;
	}
	int tot = 0;
	for (auto& p : mc)
	{
		int x, cnt;
		tie(x, cnt) = p;
		if (cnt > 2)
		{
			puts("cslnb");
			return 0;
		}
		if (cnt == 2 && (x == 0 || mc.count(x - 1)))
		{
			puts("cslnb");
			return 0;
		}
		if (cnt == 2) tot++;
	}
	if (tot > 1) puts("cslnb"), exit(0);
	int o = (sum - 1LL * n * (n - 1) / 2) & 1;
	if (o & 1) puts("sjfnb");
	else puts("cslnb");
	return 0;
}