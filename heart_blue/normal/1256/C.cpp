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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, d;
	int tot = 0;
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	if (tot + (d - 1) * (m + 1) < n) puts("NO"), exit(0);
	int rest = n - tot;
	for (int i = 1; i <= m + 1; i++)
	{
		b[i] = rest / (m + 1);
		if ((i - 1) < rest % (m + 1)) b[i]++;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= m + 1; i++)
	{
		while (b[i]--) printf("0 ");
		while (a[i]--) printf("%d ", i);
	}
	return 0;
}