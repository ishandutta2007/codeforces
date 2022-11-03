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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		pair<LL, int> ans = make_pair(1LL * n, 1);
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i) continue;
			ans = min(ans, make_pair(1LL * i / gcd(n - i, i) * (n - i), i));
			if (i != 1) ans = min(ans, make_pair(1LL * (n / i) / gcd(n - n / i, n / i) * (n - n / i), n / i));
		}
		int a, b;
		tie(ignore, b) = ans;
		a = n - b;
		printf("%d %d\n", a, b);
	}
	return 0;
}