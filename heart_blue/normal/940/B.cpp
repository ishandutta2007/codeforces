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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	LL ans = 0;
	while (n > 1)
	{
		if (n < k || k == 1)
		{
			ans += 1LL * (n - 1)*a;
			break;
		}
		if (n%k)
		{
			ans += 1LL*n % k*a;
			n -= n % k;
		}
		ans += min(1LL * a*(n - n / k), 1LL * b);
		n /= k;
	}
	cout << ans << endl;
	return 0;
}