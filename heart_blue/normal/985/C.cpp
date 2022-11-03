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
	int n, k, l;
	cin >> n >> k >> l;
	int m = n * k;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	int key = -1;
	for (int i = n; i <= m - k + 1; i++)
	{
		if (a[i] - a[1] <= l)
		{
			key = i;
		}
	}
	if (key == -1)
	{
		puts("0");
		return 0;
	}
	LL ans = 0;
	int p1 = key, p2 = m;
	while (n--)
	{
		int cnt = k;
		while (cnt > 1 && p2 > key) cnt--, p2--;
		while (cnt > 1 && p1 > 1) cnt--, p1--;
		ans += a[p1--];
	}
	cout << ans << endl;
	return 0;
}