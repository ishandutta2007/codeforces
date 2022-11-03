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
const int N = 4e6 + 10;
const int M = 2e7 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int hh, mm;
	int h, d, c, n;
	cin >> hh >> mm;
	cin >> h >> d >> c >> n;
	if (hh >= 20) hh = 20, mm = 0;
	int tot = 20 * 60 - hh * 60 - mm;
	printf("%.15f\n", min((h - 1 + n) / n * c*1.0, (h + d * tot - 1 + n) / n * (0.8*c)));
	return 0;
}