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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxv = max(maxv, a[i]);
	}
	int g = 0;
	for (int i = 1; i < n; i++)
	{
		g = gcd(g, abs(a[i] - a[i + 1]));
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (maxv - a[i]) / g;
	}
	cout << ans << ' ' << g << endl;
	return 0;
}