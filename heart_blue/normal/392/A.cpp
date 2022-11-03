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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	if (n == 0)
	{
		puts("1");
		return 0;
	}
	LL cur = n;
	LL pre = cur;
	LL ans = 0;
	for (LL i = 1; i <= n; i++)
	{
		while (i*i + cur * cur > n*n) cur--;
		if (cur == pre)
		{
			if (i == 1) ans += 2;
			else ans += 4;
		}
		else
		{
			if(i == 1) ans += (pre - cur) * 2;
			else ans += (pre - cur) * 4;
		}
		pre = cur;
	}
	ans += 2;
	cout << ans << endl;
	return 0;
}