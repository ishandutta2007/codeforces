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
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n == k || k == 0)
	{
		cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	cout << 1 << ' ';
	if (k * 3LL <= n) cout << k * 2 << endl;
	else
	{
		k -= n / 3;
		int ans = n / 3 * 2;
		if (k > 0)
		{
			if (n % 3 == 1) k--;
			else if (n % 3 == 2) k--, ans++;
		}
		ans -= k;
		cout << ans << endl;
	}

	return 0;
}