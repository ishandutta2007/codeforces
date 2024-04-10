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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int l[N];
int r[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -INF;
	a[n + 1] = -INF;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= a[i - 1]) l[i] = l[i - 1];
		else l[i] = i;
	}
	for (int i = n; i >= 1; i--)
	{
		if (a[i] <= a[i + 1]) r[i] = r[i + 1];
		else r[i] = i;
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (r[x] < l[y]) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}