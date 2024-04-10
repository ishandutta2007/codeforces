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
LL a[N];
LL rmax[N];
int rk[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	a[0] = 0;
	int n, k;
	MEM(rmax, 0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = n - k + 1; i > 0; i--)
	{
		rmax[i] = a[i + k - 1] - a[i - 1];
		rk[i] = i;
		if (rmax[i] < rmax[i + 1])
		{
			rk[i] = rk[i + 1];
			rmax[i] = rmax[i + 1];
		}
	}
	pair<LL, pair<int, int>> ans = { 0LL,{0,0} };
	for (int i = k; i + k <= n; i++)
	{
		LL o = a[i] - a[i - k];
		ans = max(ans, { o + rmax[i + 1], {-(i-k+1), -rk[i + 1]} });
	}
	cout << -ans.second.first << ' ' << -ans.second.second << endl;
	return 0;
}