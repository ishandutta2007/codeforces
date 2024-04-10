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
int a[N];
int b[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) cin >> b[i];
	if (n == m)
	{
		if (b[0] < 0) a[0] = -a[0], b[0] = -b[0];
		int g = gcd(abs(a[0]), abs(b[0]));
		printf("%d/%d\n", a[0] / g, b[0] / g);
	}
	else if (n < m)
	{
		puts("0/1");
	}
	else
	{
		if (a[0] * b[0] < 0) putchar('-');
		puts("Infinity");
	}
	return 0;
}