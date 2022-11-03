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
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		int x;
		cin >> x;
		a[x % k]++;
	}
	int ans = 0;
	for (int i = 0; i < k - i; i++)
	{
		ans += min(a[i], a[k - i]) * 2;
	}
	ans += a[0] / 2 * 2;
	if (k % 2 == 0) ans += a[k / 2] / 2 * 2;
	cout << ans << endl;
	return 0;
}