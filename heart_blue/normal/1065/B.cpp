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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 20;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	cin >> n >> m;
	if (m == 0)
	{
		printf("%lld %lld", n, n);
		return 0;
	}
	int maxv = 0;
	for (int i = 2; i <= n; i++)
	{
		if (1LL*i*(i - 1) / 2 >= m)
		{
			maxv = i;
			break;
		}
	}
	maxv = n - maxv;
	int minv = max(0LL, n - m * 2);
	cout << minv << ' ' << maxv << endl;
	return 0;
}