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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
double p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, r, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> l >> r;
		int x = r / q - (l - 1) / q;
		p[i] = x*1.0 / (r - l + 1);
	}
	p[0] = p[n];
	p[n + 1] = p[1];
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += 2000 * p[i];
		ans += 1000 * (p[i - 1] + p[i + 1])*(1 - p[i]);
	}
	printf("%.15f\n", ans);
	return 0;
}