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
const int N = 2e4 + 10;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) a[i] = 1;
	for (int i = 1; i <= n; i++) ans[i] = n - i;
	a[n] = 0;
	for (int o = 0; o < k; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			if ((a[i] >> o & 1) == ((ans[i] >> o & 1))) printf("%d ", n);
			else printf("%d ", n - (1 << o)), a[i] += 1 << o;
		}
		puts("");
	}
	return 0;
}