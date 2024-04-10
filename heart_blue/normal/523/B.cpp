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
int a[N];
double b[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, T;
	double c;
	scanf("%d%d%lf", &n, &T, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		b[i] = (b[i - 1] + a[i] * 1.0 / T) / c;
	}
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		double r1 = (sum[x] - sum[x - T]) * 1.0 / T;
		double r2 = b[x];
		double r3 = abs(r1 - r2) / r1;
		printf("%.15f %.15f %.15f\n", r1, r2, r3);
	}
	return 0;
}