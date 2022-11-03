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
const int N = 2e2 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(b, 0);
	int n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin >> c;
			if (c == '.') a[i] = j, b[j] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != 0) sum1++;
		if (b[i] != 0) sum2++;
	}
	if (sum1 != n && sum2 != n)
	{
		cout << -1 << endl;
		return 0;
	}
	if (sum1 == n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << ' ' << a[i] << endl;
		}
	}
	else if (sum2 == n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << b[i] << ' ' << i << endl;
		}
	}
	return 0;
}