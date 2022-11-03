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
const int N = 2e5 + 10;
int a[N];
int b[N];
int col[510];
int row[510];
void init()
{
	MEM(a, 0);
	a[0] = a[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i) a[j] = 1;
	}
	for (int i = N - 2; i >= 0; i--)
	{
		if (a[i]) b[i] = b[i + 1] + 1;
		else b[i] = 0;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	cin >> n >> m;
	MEM(row, 0);
	MEM(col, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			row[i] += b[x];
			col[j] += b[x];
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++) ans = min(ans, row[i]);
	for (int i = 0; i < m; i++) ans = min(ans, col[i]);
	cout << ans << endl;
	return 0;
}