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
const int N = 5e1 + 10;
int flag[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
char board[N][N];
inline bool isValid(int x, int y)
{
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return board[x][y] == 'B';
}
int check(int x, int y)
{
	MEM(flag, 0);
	for (int o1 = 0; o1 < 4; o1++)
	{
		int o2 = ((o1 ^ 2) & 2);
		int o;
		if (o2 < 2) o = 2;
		else o = 4;
		for (; o2 < o; o2++)
		{
			for (int tx = x, ty = y; isValid(tx, ty); tx += dx[o1], ty += dy[o1])
			{
				flag[tx][ty] = 1;
				for (int a = tx, b = ty; isValid(a, b); a += dx[o2], b += dy[o2])
				{
					flag[a][b] = 1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cnt += flag[i][j];
		}
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	int q;
	cin >> n >> q;
	while (q--)
	{
		LL x;
		string str;
		cin >> x >> str;
		for (auto &c : str)
		{
			if (c == 'U')
			{
				LL o = x&-x;
				LL t = x;
				x |= o << 1 | o;
				x ^= o;
				if (x > n) x = t;
			}
			else
			{
				if (x % 2 == 0)
				{
					LL o = x&-x;
					o >>= 1;
					if (c == 'L') x -= o;
					else x += o;
				}
			}
		}
		printf("%lld\n", x);
	}
	return 0;
}