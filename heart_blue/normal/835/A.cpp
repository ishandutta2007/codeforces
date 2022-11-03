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
const int N = 2e2 + 10;
int check(LL x, LL y, LL a, LL b)
{
	LL o = x*b - a*y;
	if (o > 0) return 1;
	if (o == 0) return 0;
	if (o < 0) return -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int s, v1, t1, v2, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int a = t1 * 2 + s*v1;
	int b = t2 * 2 + s*v2;
	if (a < b) puts("First");
	else if (a > b) puts("Second");
	else puts("Friendship");
	return 0;
}