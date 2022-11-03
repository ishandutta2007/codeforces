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
int a[N];
void solve(int from, int to, int sum)
{
	if (from == to) return;
	int r = sum % (to - from);
	int d = sum / (to - from);
	for (int i = from; i < to; i++) a[i] += d;
	for (int i = from; i < from + r; i++) a[i] ++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, l, r, sum, sumk;
	cin >> n >> k >> l >> r >> sum >> sumk;
	for (int i = 0; i < n; i++) a[i] = l;
	sum -= n*l;
	sumk -= k*l;
	sum -= sumk;
	solve(0, k, sumk);
	solve(k, n, sum);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}