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
const int N = 1e6 + 10;
void exgcd(LL a, LL b, LL &g, LL &x, LL &y)
{
	if (b == 0) g = a, x = 1, y = 0;
	else exgcd(b, a%b, g, y, x), y -= a / b*x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, c;
	cin >> a >> b >> c;
	LL g, x, y;
	exgcd(a, b, g, x, y);
	if (c%g) puts("-1");
	else
	{
		c /= -g;
		x *= c;
		y *= c;
		cout << x << ' ' << y << endl;
	}
	return 0;
}