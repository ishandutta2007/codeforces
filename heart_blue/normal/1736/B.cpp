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
const int N = 1e6 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 2; i <= n; i++)
		{
			b[i] = a[i - 1] * a[i] / gcd(a[i - 1], a[i]);
		}
		b[1] = a[1];
		b[n + 1] = a[n];
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != gcd(b[i], b[i + 1]))
			{
				flag = 0;
			}
		}
		if (flag) puts("YES");
		else puts("NO");

	}
	return 0;
}