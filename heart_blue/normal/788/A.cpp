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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL a[N];
LL getans(int n)
{
	LL maxv = -INF*INF;
	LL sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] > a[i]) sum += a[i];
		else sum = a[i];
		maxv = max(maxv, sum);
	}
	return maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i + 1 < n; i++)
	{
		a[i] -= a[i + 1];
		a[i] = abs(a[i]);
		if (i & 1) a[i] = -a[i];
	}
	n--;
	LL ans1 = getans(n);
	for (int i = 0; i < n; i++) a[i] = -a[i];
	LL ans2 = getans(n);
	cout << max(ans1, ans2) << endl;
	return 0;
}