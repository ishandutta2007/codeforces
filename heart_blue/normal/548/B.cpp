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
int a[N][N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		b[i] = 0;
		int sum = 0;
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			sum = (sum + a[i][j])*a[i][j];
			b[i] = max(b[i], sum);
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] ^= 1;
		int sum = 0;
		b[x] = 0;
		for (int i = 1; i <= m; i++)
		{
			sum = (sum + a[x][i])*a[x][i];
			b[x] = max(b[x], sum);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans, b[i]);
		cout << ans << '\n';
	}
	return 0;
}