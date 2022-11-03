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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int l, r;
		LL m;
		scanf("%d%d%lld", &l, &r, &m);
		for (int i = l; i <= r; i++)
		{
			int rest = m % i;
			if (m / i > 0 && rest <= r - l)
			{
				printf("%d %d %d\n", i, l + rest, l);
				break;
			}
			rest = (i - rest) % i;
			if (rest <= r - l)
			{
				printf("%d %d %d\n", i, l, l + rest);
				break;
			}
		}
	}
	return 0;
}