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
const int N = 2e5 + 10;
int ans[N];
char str[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		if (n % i)
		{
			ans[i] = ans[gcd(n, i)];
			continue;
		}
		int ok = 1;
		for (int j = 1; j <= i; j++)
		{
			int sum = 0;
			for (int k = j; k <= n; k += i)
			{
				sum ^= str[k] - '0';
			}
			if (sum)
			{
				ok = 0;
				break;
			}
		}
		ans[i] = ok;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += ans[i];
	printf("%d\n", sum);
	return 0;
}