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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h, m;
	cin >> n >> h >> m;
	fill(a + 1, a + n + 1, h);
	while (m--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		for (int i = l; i <= r; i++) a[i] = min(a[i], x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i] * a[i];
	cout << ans << endl;
	return 0;
}