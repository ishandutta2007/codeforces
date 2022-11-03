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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ax = (a - 1) / m, ay = (a - 1) % m;
	int bx = (b - 1) / m, by = (b - 1) % m;
	if (ax == bx)
	{
		cout << 1 << endl;
		return 0;
	}
	if (ay == 0)
	{
		if (b == n || b%m == 0) cout << 1 << endl;
		else cout << 2 << endl;
		return 0;
	}
	if (ax + 1 == bx)
	{
		cout << 2 << endl;
		return 0;
	}
	if (b == n || by == m - 1)
	{
		cout << 2 << endl;
		return 0;
	}
	if (by + 1 == ay) cout << 2 << endl;
	else cout << 3 << endl;

	return 0;
}