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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, y, z, w;
	LL a, b, c, d;
	int n;
	a = b = c = 0;
	d = 1;
	cin >> n;
	while (n--)
	{
		x = b + c + d;
		y = a + c + d;
		z = a + b + d;
		w = a + b + c;
		while (x >= INF) x -= INF;
		while (y >= INF) y -= INF;
		while (z >= INF) z -= INF;
		while (w >= INF) w -= INF;
		a = x, b = y, c = z, d = w;
	}
	cout << d << endl;
	return 0;
}