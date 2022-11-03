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
const int N = 1e5 + 10;
int a[3][3];
int row[3];
int col[3];
bool check(int x)
{
	MEM(row, 0);
	MEM(col, 0);
	for (int i = 0; i < 3; i++)
	{
		a[i][i] = 0;
		for (int j = 0; j < 3; j++)
		{
			row[i] += a[i][j];
		}
	}
	a[0][0] = x;
	row[0] += x;
	a[1][1] = row[0] - row[1];
	a[2][2] = row[0] - row[2];
	MEM(row, 0);
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 3; i++)
	{
		sum1 += a[i][i];
		sum2 += a[i][3 - i - 1];
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] <= 0 || a[i][j] > 1e5) return false;
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	if (sum1 != sum2) return false;
	if (row[0] != sum1) return false;
	for (int i = 0; i < 3; i++)
	{
		if (sum1 != row[i]) return false;
		if (sum1 != col[i]) return false;
	}
	return true;
}

void output()
{
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 1e5; i++)
	{
		if (check(i))
		{
			output();
			break;
		}
	}
	return 0;
}