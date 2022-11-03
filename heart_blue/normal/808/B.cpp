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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL tot = 0;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i <= k) sum += a[i];
	}
	tot = sum;
	for (int i = k + 1; i <= n; i++)
	{
		sum -= a[i - k];
		sum += a[i];
		tot += sum;
	}
	printf("%.15f\n", tot * 1.0/ (n - k + 1));
	return 0;
}