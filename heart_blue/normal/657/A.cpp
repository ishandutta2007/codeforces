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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d, h;
	cin >> n >> d >> h;
	if (2 * h < d)
	{
		puts("-1");
		return 0;
	}
	if (h == 1 && d == 1 && n > 2)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= h; i++)
	{
		printf("%d %d\n", i, i + 1);
	}
	for (int i = h + 1; i <= d; i++)
	{
		if (i == h + 1) printf("%d %d\n", 1, i + 1);
		else printf("%d %d\n", i, i + 1);
	}
	int o;
	if (h == d) o = 2;
	else o = 1;
	for (int i = d + 1; i < n; i++)
	{
		printf("%d %d\n", o, i + 1);
	}
	return 0;
}