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
const LL INF = 1e8 + 7;
const int N = 2e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		puts("NO");
		return 0;
	}
	int l = 1, r = n + 1;
	int x = 1, y = 2;
	for (int i = 1; i <= n; i++)
	{
		ans[l++] = x;
		ans[r++] = y;
		swap(x, y);
		x += 2;
		y += 2;
	}
	puts("YES");
	for (int i = 1; i <= 2 * n; i++)
		printf("%d%c", ans[i], " \n"[i == 2 * n]);
	return 0;
}