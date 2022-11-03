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
const int N = 1e6 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int x;
		scanf("%d", &x);
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		LL ans = n;
		for (int i = 1; i <= x; i++)
		{
			int cnt = str[i] - '0';
			ans = ans + (ans - i) * (cnt - 1);
			ans %= INF;
			int len = n - i;
			int r = min(x, len * cnt + i);
			for (int j = n + 1; j <= r; j++) str[j] = str[j - len];
			n = r;
		}
		if (ans < 0) ans += INF;
		printf("%lld\n", ans);
	}
	return 0;
}