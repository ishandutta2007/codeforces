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
const int N = 5e3 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int refrain(int l1, int r1, int l2, int r2)
{
	return max(0, min(r2, r1) - max(l1, l2) + 1);
}
int solve(int l1, int r1, int t1, int l2, int r2, int t2)
{
	int g = gcd(t1, t2);
	int o = (l2 - l1) % g;
	if (o < 0) o += g;
	return refrain(l1, r1, l1 + o, l1 + o + (r2 - l2));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int la, ra, ta;
	int lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	cout << max(solve(la, ra, ta, lb, rb, tb), solve(lb, rb, tb, la, ra, ta)) << endl;
	return 0;
}