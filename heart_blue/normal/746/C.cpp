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
const int N = 4e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int s, x1, x2;
	int t1, t2;
	int p, d;
	cin >> s >> x1 >> x2;
	cin >> t1 >> t2;
	cin >> p >> d;
	int ans = abs(x2 - x1)*t2;
	if (x1 > x2)
	{
		x1 = s - x1;
		x2 = s - x2;
		p = s - p;
		d = -d;
	}
	if (p <= x1)
	{
		if (d == 1) ans = min(ans, (x2 - p)*t1);
		else ans = min(ans, (p * 2 + x2 - p)*t1);
	}
	else
	{
		if (d == 1) ans = min(ans, (2 * s + x2 - p)*t1);
		else ans = min(ans, (p * 2 + x2 - p)*t1);
	}
	cout << ans << endl;
	return 0;
}