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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 11; i++)
		cin >> a[i];
	for (int i = 11; i > 0; i--)
	{
		double ans = sqrt(fabs(1.0 * a[i])) + 5 * a[i] * a[i] * a[i];
		if (ans < 400 + 1e-9) printf("f(%d) = %.2f\n", a[i], ans);
		else printf("f(%d) = MAGNA NIMIS!\n", a[i]);
	}
	return 0;
}