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
const int N = 1e6 + 10;

vector<LL> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL m = 1e6;
	for (LL i = 2; i <= m; i++)
	{
		v.push_back(i*i*i);
	}
	LL l = 1, r = m*m*m;
	LL ans = -1;
	LL o;
	cin >> o;
	while (l <= r)
	{
		LL cnt = 0;
		LL mid = (l + r) / 2;
		for (auto &x : v) cnt += mid / x;
		if (cnt > o) r = mid - 1;
		else if (cnt == o) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}