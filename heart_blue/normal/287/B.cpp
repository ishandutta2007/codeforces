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
LL check(LL x)
{
	return x*(x - 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	LL l = 1, r = k;
	LL ans = k+1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL tot = check(k) - check(mid) + 1;
		if (tot >= n) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << k - ans << endl;
	return 0;
}