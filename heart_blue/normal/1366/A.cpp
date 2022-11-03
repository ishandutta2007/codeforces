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
const int N = 5e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		int ans = 0;
		while (a - b > 1 && b > 0)
		{
			int o = min((a - b) / 2, b);
			ans += o;
			a -= 2 * o;
			b -= o;
		}
		int o = min(a, b) / 3;
		ans += 2 * o;
		a -= 3 * o;
		b -= 3 * o;
		if (a > 1 && b > 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}