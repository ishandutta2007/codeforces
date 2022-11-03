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
const int N = 2e2 + 10;
char board[N][N];
pair<int, int> check(int n, int m, char X)
{
	int l = m, r = 0, u = n, d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != X) continue;
			l = min(l, j);
			r = max(r, j);
			u = min(u, i);
			d = max(d, i);
		}
	}
	return { max(r - l + 1,0),max(0,d - u + 1) };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	auto R = check(n, m, 'R');
	auto G = check(n, m, 'G');
	auto B = check(n, m, 'B');
	if (R == G && G == B && R.first * R.second * 3 == n*m) puts("YES");
	else puts("NO");
	return 0;
}