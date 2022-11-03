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
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int cnt1 = 0, cnt0 = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x & 1) cnt1++;
		else cnt0++;
	}
	if (n == k)
	{
		if (cnt1 % 2 == 0) puts("Daenerys");
		else puts("Stannis");
		return 0;
	}
	n -= k;
	int b = n / 2;
	int a = n - b;
	if (b >= cnt1)
	{
		puts("Daenerys");
		return 0;
	}
	if (b >= cnt0)
	{
		if (k % 2 == 0)
		{
			puts("Daenerys");
			return 0;
		}
	}
	if (a >= cnt0)
	{
		if (k % 2 == 1)
		{
			puts("Stannis");
			return 0;
		}
	}
	if (a == b) puts("Daenerys");
	else puts("Stannis");
	return 0;
}