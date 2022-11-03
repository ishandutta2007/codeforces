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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL sum = 0;
	LL maxv = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i], maxv = max(maxv, a[i]);
	sort(a, a + n);
	sum -= a[0];
	LL res = maxv * (n - 1) - sum;
	if (res >= a[0])
	{
		cout << maxv << endl;
	}
	else
	{
		res = a[0] - res;
		LL ans = res / (n - 1) + (res % (n - 1) != 0);
		cout << maxv + ans << endl;
	}
	return 0;
}