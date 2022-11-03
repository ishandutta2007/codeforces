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
#include <random>
#include <cassert>
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
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	LL l = 1, r = 2*INF;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL tot = 0;
		for (int i = (n + 1) / 2; i <= n; i++)
		{
			tot += max(0, mid - a[i]);
		}
		if (tot <= k) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}