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
	int n, q, k;
	scanf("%d%d%d", &n, &q, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r)
		{
			printf("%d\n", k - 1);
		}
		else
		{
			printf("%d\n", (k - (r - l + 1)) * 2 - (a[l] - 1) - (k - a[r]));
		}
	}
	return 0;
}