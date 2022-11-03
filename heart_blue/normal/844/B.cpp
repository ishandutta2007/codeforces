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
const int N = 1e2 + 10;
int row[N];
int col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(row, 0);
	MEM(col, 0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if (x == 1) row[i]++, col[j]++;
		}
	}
	LL ans = n*m;
	for (int i = 1; i <= n; i++) ans += max(0LL, (1LL << (row[i])) - 1 - row[i]) + max(0LL, (1LL << (m - row[i])) - 1 - m + row[i]);
	for (int i = 1; i <= m; i++) ans += max(0LL, (1LL << (col[i])) - 1 - col[i]) + max(0LL, (1LL << (n - col[i])) - 1 - n + col[i]);
	cout << ans << endl;
	return 0;
}