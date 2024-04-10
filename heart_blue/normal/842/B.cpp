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
	int r, d;
	cin >> r >> d;
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		int x, y, R;
		cin >> x >> y >> R;
		if (x*x + y*y < R*R) continue;
		double d1 = sqrt(x*x + y*y) - R;
		double d2 = sqrt(x*x + y*y) + R;
		if (d1 >= r - d && d2 <= r) ans++;
	}
	cout << ans << endl;
	return 0;
}