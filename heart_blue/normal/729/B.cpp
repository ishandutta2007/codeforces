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
const int N = 2e3 + 10;
int a[N][N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(b, 0);
	int o = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		o = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) o = 1, b[j] = 1;
			else ans += o + b[j];
		}
	}
	MEM(b, 0);
	o = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		o = 0;
		for (int j = m - 1; j >= 0; j--)
		{
			if (a[i][j] == 1) o = 1, b[j] = 1;
			else ans += o + b[j];
		}
	}
	cout << ans << endl;
	return 0;
}