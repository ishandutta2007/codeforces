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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int l, r;
	int u, d;
	cin >> n;
	l = d = INF;
	r = u = -INF;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		l = min(x, l);
		r = max(x, r);
		u = max(y, u);
		d = min(y, d);
	}
	int ans = (u - d)*(r - l);
	if (ans == 0) ans = -1;
	cout << ans << endl;
	return 0;
}