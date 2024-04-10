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
int n, d, x, y, v, r;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 2 * n - 2; i >= 0; i -= 2) {
		r = 4 * v | (d >> i) & 3;
		x = (x << 1) | (0X936C >> r) & 1;
		y = (y << 1) | (0X39C6 >> r) & 1;
		v = (0X3E6B94C1 >> 2 * r) & 3;
	}
	printf("%d %d", x, y);
	return 0;
}