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
const int N = 1e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, x, y;
	cin >> n >> x >> y;
	if (n > y)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		int o = n - i;
		LL tot = i;
		tot += (y / o)*(y / o)*o;
		tot += (2 * (y / o) - 1)*(y%o);
		if (tot >= x)
		{
			for (int j = 0; j < i; j++) cout << 1 << '\n';
			for (int j = 0; j < y%o; j++) cout << y / o + 1 << '\n';
			for (int j = 0; j < o - y%o; j++) cout << y / o << '\n';
			return 0;
		}
		y--;
	}
	cout << -1 << endl;
	return 0;
}