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
const int N = 2e5 + 10;
LL x[N];
LL y[N];
LL cross(int i, int j)
{
	return x[i] * y[j] - x[j] * y[i];
}
LL dot(int i, int j)
{
	LL dx = x[i] - x[j];
	LL dy = y[i] - y[j];
	return dx*dx + dy*dy;
}
LL area(int i, int j, int k)
{
	return abs(cross(i, j) + cross(j, k) + cross(k, i));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL minv = LLONG_MAX;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	int key = 2;
	for (int i = 2; i <= n; i++)
	{
		if (minv > dot(1, i))
		{
			key = i;
			minv = dot(1, i);
		}
	}
	minv = LLONG_MAX;
	int k2 = 2;
	for (int i = 2; i <= n; i++)
	{
		if (i == key) continue;
		if (area(1, key, i) < 1e-6) continue;
		if (minv > area(1, key, i))
		{
			minv = area(1, key, i);
			k2 = i;
		}
	}
	cout << 1 << ' ' << key << ' ' << k2 << endl;
	return 0;
}