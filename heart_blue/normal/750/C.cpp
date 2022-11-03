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
const int N = 2e5 + 10;
int c[N];
int d[N];
void cross(int &l1, int &r1, int l2, int r2)
{
	l1 = max(l1, l2);
	r1 = min(r1, r2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = 1900;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i] >> d[i];
		tot += abs(c[i]);
	}
	int l = -INF, r = INF;
	int l1 = 1900, r1 = INF;
	int l2 = -INF, r2 = 1899;
	for (int i = 0; i < n; i++)
	{
		if (d[i] == 2) cross(l, r, l2, r2);
		else cross(l, r, l1, r1);
		r += c[i];
		l += c[i];
	}
	if (l > r) puts("Impossible");
	else if (r > tot) puts("Infinity");
	else printf("%d\n", r);
	return 0;
}