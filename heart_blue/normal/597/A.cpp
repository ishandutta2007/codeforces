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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL solve(LL n, LL k)
{
	return n / k;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL k, a, b;
	cin >> k >> a >> b;
	if (a >= 0) cout << solve(b, k) - solve(max(0LL, a - 1), k) + (a == 0) << endl;
	else if (b <= 0) cout << solve(-a, k) - solve(max(0LL, -b - 1), k) + (b == 0) << endl;
	else cout << solve(b, k) + solve(-a, k) + 1 << endl;
	return 0;
}