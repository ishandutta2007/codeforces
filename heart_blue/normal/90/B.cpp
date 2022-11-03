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
int flag[N][N];
char board[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(flag, 0);
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		map<char, int> mc;
		for (int j = 0; j < m; j++) mc[board[i][j]]++;
		for (int j = 0; j < m; j++)
		{
			if (mc[board[i][j]] > 1) flag[i][j] = 1;
		}
	}
	for (int j = 0; j < m; j++)
	{
		map<char, int> mc;
		for (int i = 0; i < n; i++) mc[board[i][j]]++;
		for (int i = 0; i < n; i++)
		{
			if (mc[board[i][j]] > 1) flag[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j]) continue;
			putchar(board[i][j]);
		}
	}
	return 0;
}