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
const int N = 1e5 + 10;
int check(int a, int b, int c)
{
	int o[4] = { 0 };
	o[a] = 1;
	o[b] = 1;
	o[c] = 1;
	for (int i = 1; i <= 3; i++) if (o[i] == 0) return i;
	return 0;
}
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y, z;
	cin >> n >> m;
	MEM(a, 0);
	while (m--)
	{
		cin >> x >> y >> z;
		if (a[x] == 0) a[x] = check(a[x], a[y], a[z]);
		if (a[y] == 0) a[y] = check(a[x], a[y], a[z]);
		if (a[z] == 0) a[z] = check(a[x], a[y], a[z]);
	}
	for (int i = 1; i <= n; i++) if (a[i] == 0) a[i] = 1;
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}