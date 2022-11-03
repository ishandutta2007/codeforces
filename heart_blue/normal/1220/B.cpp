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
const int N = 2e3 + 10;
int a[N][N];
int g = 0;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (i == 1) g = gcd(g, a[i][j]);
		}
	}
	LL a1 = g;
	LL a2 = a[1][2] / g;
	LL a3 = a[1][3] / g;
	int t = a[2][3] / a2 / a3;
	a1 /= int(sqrt(t) + 0.5);
	cout << a1;
	for (int i = 2; i <= n; i++) cout << ' ' << a[1][i] / a1;
	return 0;
}