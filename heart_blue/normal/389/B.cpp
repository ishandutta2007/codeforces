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
const int N = 2e2 + 10;
char chess[N][N];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> chess[i][j];
			if (chess[i][j] == '#') total++;
		}
	}
	auto check = [&](int x, int y) ->bool
	{
		for (int i = 0; i < 5; i++)
		{
			int tx = dx[i] + x;
			int ty = dy[i] + y;
			if (chess[tx][ty] != '#') return false;
		}
		for (int i = 0; i < 5; i++)
		{
			int tx = dx[i] + x;
			int ty = dy[i] + y;
			chess[tx][ty] = '.';
		}
		return true;
	};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check(i, j))
			{
				total -= 5;
			}
		}
	}
	if (total == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}