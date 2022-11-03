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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, a, b, c;
	cin >> n >> a >> b >> c;
	LL ans = 0;
	if (a <= b - c)
	{
		ans = n / a;
	}
	else
	{
		LL o = (n - b) / (b - c);
		if (o < 0) o = 0;
		n -= o*(b - c);
		if (n >= b) o++, n -= (b - c);
		ans = max(ans, o + n / a);
	}
	cout << ans << endl;
	return 0;
}