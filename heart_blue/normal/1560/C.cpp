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
const int N = 1e5 + 10;
bool check(int x)
{
	if (x % 3 == 0 || x % 10 == 3) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int k;
		scanf("%d", &k);
		int x = sqrt(k) + 10;
		while (x * x >= k) x--;
		x++;
		int len = x * x - k + 1;
		if (len <= x) printf("%d %d\n", x, len);
		else
		{
			len = x * 2 - 1 - len + 1;
			printf("%d %d\n", len, x);
		}
	}
	return 0;
}