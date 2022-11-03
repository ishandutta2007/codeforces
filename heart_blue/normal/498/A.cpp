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
const int N = 3e3 + 10;
LL a, b, c;
bool check(LL x, LL y)
{
	return a * x + b * y + c > 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL xa, ya;
	LL xb, yb;
	cin >> xa >> ya;
	cin >> xb >> yb;
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		cin >> a >> b >> c;
		if (check(xa, ya) != check(xb, yb))
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}