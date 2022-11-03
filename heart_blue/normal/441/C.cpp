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
const int N = 3e2 + 10;
int n, m;
void nex(int& x, int& y, int& o)
{
	cout << ' ' << x << ' ' << y;
	y += o;
	if (y == 0) y = 1, x++, o = 1;
	else if (y > m) y = m, x++, o = -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> n >> m >> k;
	int tot = 0;
	int x = 1;
	int y = 1;
	int o = 1;
	while (--k)
	{

		cout << 2;
		int t = 2;
		while (t--)
		{
			nex(x, y, o);
			tot++;
		}
		cout << endl;
	}
	cout << n * m - tot;
	while (tot++ < n * m) nex(x, y, o);
	cout << endl;
	return 0;
}