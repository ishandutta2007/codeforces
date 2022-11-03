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
const int N = 2e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, p, w, d;
	cin >> n >> p >> w >> d;
	for (int i = 0; i < N; i++)
	{
		if (p - i * d < 0) break;
		if ((p - i * d) % w) continue;
		LL x = i;
		LL y = (p - i * d) / w;
		if (x + y <= n)
		{
			cout << y << ' ' << x << ' ' << n - x - y << endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}