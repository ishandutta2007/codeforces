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
const int N = 1e6 + 10;
const int mod = 998244353;
int check(int n)
{
	int cnt = 0;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
			n /= i, cnt++;
	}
	if (n > 1) cnt++;
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
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		int cnt1 = check(a);
		int cnt2 = check(b);
		if (k > cnt1 + cnt2)
		{
			puts("No");
			continue;
		}
		if (k == 1)
		{
			if (a != b && (a % b == 0 || b % a == 0))
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("Yes");
	}
	return 0;
}