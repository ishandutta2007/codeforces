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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		b[i] = (b[i - 1] + b[i]) % c;
	}
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		if (i <= m)
		{
			r = i;
			l = max(1, i - (n - m));
		}
		else
		{
			r = m;
			l = max(1, m - (n - i));
		}
		a[i] += b[r] - b[l - 1];
		a[i] %= c;
		if (a[i] < 0) a[i] += c;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}