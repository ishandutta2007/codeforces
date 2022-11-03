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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		if (a < b || a < c) tie(a, b, c) = make_tuple(b, c, a);
	}
	b -= a - 1;
	c -= a - 1;
	a -= a - 1;
	if (c > 0) tie(a, b, c) = make_tuple(c, a, b);
	if (c > 0) c--, b--, a--;
	if (b > 0) b--, a--;
	if (a > 0) a--;
	LL ans = 0;
	if (b < 0) ans -= b;
	if (c < 0) ans -= c;
	cout << ans << endl;
	return 0;
}