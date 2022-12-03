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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int getcnt(int n, int x)
{
	int cnt = 0;
	while (n % x == 0) cnt++, n /= x;
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt2 = getcnt(n, 2);
		int cnt5 = getcnt(n, 5);
		int key = 1;
		int s = m;
		while (cnt2 < cnt5 && s >= 2)
		{
			s /= 2, key *= 2;
			cnt2++;
		}
		while (cnt2 > cnt5 && s >= 5)
		{
			s /= 5, key *= 5;
			cnt5++;
		}
		while (s >= 10)
		{
			s /= 10;
			key *= 10;
		}
		printf("%lld\n", 1LL * n * (m / key) * key);
	}
	return 0;
}