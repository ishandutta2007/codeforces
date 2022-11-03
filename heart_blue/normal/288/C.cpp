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
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int x = 1;
	int m = n;
	while (x <= n) x *= 2;
	x /= 2;
	while (n > 3)
	{
		int l = x - 1, r = x;
		while (r <= n)
		{
			a[l] = r, a[r] = l;
			l--, r++;
		}
		n = l;
		while(x > 0 && x > n) x >>= 1;
	}
	if (n == 1) a[1] = 0, a[0] = 1;
	else if (n == 2) a[1] = 2, a[2] = 1;
	else if (n == 3) a[0] = 3, a[1] = 2, a[2] = 1;
	printf("%lld\n", m*LL(m + 1));
	for (int i = 0; i <= m; i++) printf("%d ", a[i]);
	return 0;
}