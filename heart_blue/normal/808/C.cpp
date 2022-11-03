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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[N];
int pos[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = (a[i] + 1) / 2;
		w -= b[i];
	}
	if (w < 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) pos[i] = i;
	sort(pos, pos + n, [&](int x, int y)-> bool
	{
		return a[x] > a[y];
	});
	for (int i = 0; i < n; i++)
	{
		int p = pos[i];
		int o = min(a[p] - b[p], w);
		b[p] += o;
		w -= o;
	}
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}