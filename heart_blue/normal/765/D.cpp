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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int f[N];
int g[N];
int h[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int m = 0;
	MEM(h, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
		if (f[i] == i)
		{
			h[++m] = i;
			g[i] = m;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (g[f[i]] == 0)
		{
			cout << "-1" << endl;
			return 0;
		}
		g[i] = g[f[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		if (h[g[i]] != f[i])
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << m << endl;
	for (int i = 1; i <= n; i++) cout << g[i] << ' ';
	cout << endl;
	for (int i = 1; i <= m; i++) cout << h[i] << ' ';
	return 0;
}