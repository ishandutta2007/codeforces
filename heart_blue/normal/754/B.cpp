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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
char a[N][N];
int n = 4;
bool isWin(char o)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != o) continue;
			for (int k = 0; k < 4; k++)
			{
				char &c1 = a[i + dx[k]][j + dy[k]];
				char &c2 = a[i + dx[k + 4]][j + dy[k + 4]];
				if (c1 == c2 && c1 == a[i][j])
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, '.');
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != '.') continue;
			a[i][j] = 'x';
			if (isWin('x'))
			{
				cout << "YES" << endl;
				return 0;
			}
			a[i][j] = '.';
		}
	}
	cout << "NO" << endl;
	return 0;
}