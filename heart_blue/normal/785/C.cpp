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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	cin >> n >> m;
	m = min(n, m);
	LL sum = n - m;
	LL l = 0, r = INF * 2;
	LL ret = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (mid*(mid + 1) / 2 >= sum) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ret + m << endl;
	return 0;
}