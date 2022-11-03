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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	int l = min(abs(x - a[0]) + a[n - 2] - a[0], abs(x - a[1]) + a[n - 1] - a[1]);
	int r = min(abs(x - a[n - 1]) + a[n - 1] - a[1], abs(x - a[n - 2]) + a[n - 2] - a[0]);
	cout << min(l, r) << endl;
	return 0;
}