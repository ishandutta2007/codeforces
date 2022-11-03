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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int maxv1 = 0, maxv2 = 0;
		int n, m;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			maxv1 = max(maxv1, x);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			maxv2 = max(maxv2, x);
		}
		if (maxv1 > maxv2) puts("Alice\nAlice");
		else if (maxv1 < maxv2) puts("Bob\nBob");
		else puts("Alice\nBob");

	}
	return 0;
}