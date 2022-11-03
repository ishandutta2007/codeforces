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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		if (n < k)
		{
			puts("NO");
			continue;
		}
		if ((n - k + 1) % 2 == 1)
		{
			puts("YES");
			for (int i = 1; i < k; i++) printf("1 ");
			printf("%d\n", n - k + 1);
			continue;
		}
		if (n > 2 * k - 2 && n % 2 == 0)
		{
			puts("YES");
			for (int i = 1; i < k; i++) printf("2 ");
			printf("%d\n", n - 2 * k + 2);
			continue;
		}
		puts("NO");
	}
	return 0;
}