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
const int N = 2e3 + 10;
double ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	double p;
	cin >> n >> p >> t;
	for (int i = 0; i <= n; i++) ans[i] = 0;
	ans[0] = 1;
	while (t--)
	{
		for (int i = n; i > 0; i--)
		{
			ans[i] += ans[i - 1] * p;
			ans[i-1] *= (1 - p);
		}
	}
	double sum = 0;
	for (int i = 1; i <= n; i++) sum += i*ans[i];
	printf("%.15f\n", sum);

	return 0;
}