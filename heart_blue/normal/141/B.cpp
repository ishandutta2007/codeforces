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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, x, y;
	cin >> a >> x >> y;
	if (abs(x) >= a || y % a == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int o = y / a;
	if (o == 0 || o % 2 == 1)
	{
		if (abs(x) * 2 >= a) cout << -1 << endl;
		else
		{
			if (o == 0) cout << 1 << endl;
			else cout << o / 2 * 3 + 2 << endl;
		}
		return 0;
	}
	if (x < 0) cout << o / 2 * 3 << endl;
	else if (x > 0) cout << o / 2 * 3 + 1 << endl;
	else cout << -1 << endl;
	return 0;
}