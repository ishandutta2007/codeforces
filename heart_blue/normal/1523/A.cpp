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
char a[N];
int b[N];
void check(int n)
{
	a[0] = a[n + 1] = '0';
	for (int i = 1; i <= n; i++)
	{
		if (a[i - 1] - '0' + a[i + 1] - '0' == 1)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		a[i] |= b[i];
	a[n + 1] = 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%s", a + 1);
		m = min(m, n);
		while (m--)
			check(n);
		puts(a + 1);
	}
	return 0;
}