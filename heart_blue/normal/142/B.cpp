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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1)
	{
		cout << m << endl;
		return 0;
	}
	if (n == 2)
	{
		int ans = m / 4 * 4;
		m %= 4;
		if (m == 1) ans += 2;
		if (m >= 2) ans += 4;
		cout << ans << endl;
		return 0;
	}
	cout << n * (m / 2) + (n + 1) / 2 * (m & 1) << endl;

	return 0;
}