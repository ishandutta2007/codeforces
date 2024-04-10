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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int a, b;
	int c, d;
	cin >> n >> m >> a >> b >> c >> d;
	int flag = 0;
	for (int i = 0; i < 2; i++)
	{
		swap(a, b);
		for (int j = 0; j < 2; j++)
		{
			swap(c, d);
			if (a + c <= n && max(b, d) <= m) flag = 1;
			if (a + c <= m && max(b, d) <= n) flag = 1;
		}
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}