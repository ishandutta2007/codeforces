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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	char c;
	scanf("%lld%c", &n, &c);
	LL ans = (n-1) / 4 * 12;
	if (n % 4 == 1 || n % 4 == 2) ans += n - 1;
	else ans += n - 3;
	if (n % 4 == 2 || n % 4 == 0) ans += 6;
	if (c >= 'd') ans += 'f' - c + 1;
	else ans += 3 + c - 'a' + 1;
	cout << ans << endl;
	return 0;
}