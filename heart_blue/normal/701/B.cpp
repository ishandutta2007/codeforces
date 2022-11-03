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
const int N = 1e6 + 10;
int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(b, 0);
	int row, col;
	int n, m;
	cin >> n >> m;
	row = col = n;
	LL tot = (LL)n*n;
	LL sum = 0;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (!a[x]) sum += col;
		if (!b[y]) sum += row;
		if (!a[x] && !b[y]) sum--;
		if (!a[x]) row--;
		if (!b[y]) col--;
		a[x] = 1;
		b[y] = 1;
		cout << tot - sum << '\n';

	}
	return 0;
}