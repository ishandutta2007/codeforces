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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i] -= x;
	}
	sort(a, a + n);
	for (int i = k; i < n; i++)
	{
		ans -= max(0, a[i]);
	}
	cout << ans << endl;
	return 0;
}