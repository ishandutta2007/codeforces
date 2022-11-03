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
	LL n, m;
	cin >> n >> m;
	while (m--)
	{
		LL x, y;
		cin >> x >> y;
		LL offset;
		if ((x + y) % 2 == 0)
		{
			offset = 1LL * (x - 1) / 2 * n;
			if (x & 1) offset += y / 2 + 1;
			else offset += (n - n / 2) + y / 2;
		}
		else
		{
			offset = (1LL * n*n + 1) / 2;
			offset += 1LL * (x - 1) / 2 * n;
			if (x & 1) offset += y / 2;
			else offset += n / 2 + y / 2 + 1;
		}
		printf("%lld\n", offset);
	}
	return 0;
}