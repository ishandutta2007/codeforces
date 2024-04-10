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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	int x, y, z;
	int n;
	cin >> n;
	a = 0;
	b = 0;
	c = 0;
	while (n--)
	{
		int t;
		cin >> t;
		x = y = z = INF;
		if (t & 1) x = min(c, b);
		if (t & 2) y = min(c, a);
		z = min(a, min(b, c)) + 1;
		a = x;
		b = y;
		c = z;
	}
	cout << min(a, min(b, c)) << endl;
	return 0;
}