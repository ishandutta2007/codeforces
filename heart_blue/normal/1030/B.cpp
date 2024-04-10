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
const int N = 1e3 + 10;
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	n *= 2, d *= 2;
	for (int i = 0; i <= d; i++)
	{
		int x = i, y = d - i;
		for (int j = 0; j <= n - d; j++)
		{
			flag[x][y] = 1;
			x++, y++;
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x *= 2, y *= 2;
		if (flag[x][y]) puts("YES");
		else puts("NO");
	}
	return 0;
}