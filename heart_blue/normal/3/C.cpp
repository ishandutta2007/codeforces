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
int n = 3;
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
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'X') cnt1++;
			if (a[i][j] == '0') cnt2++;
		}
	}
	if (cnt1 != cnt2 && cnt1 != cnt2+1)
	{
		cout << "illegal" << endl;
		return 0;
	}
	bool win1 = isWin('X');
	bool win2 = isWin('0');
	bool step1 = false;
	bool step2 = false;
	if (cnt1 == cnt2) step1 = true;
	if (cnt1 == cnt2 + 1) step2 = true;
	if ((step1 && win1) || (step2 && win2))
	{
		cout << "illegal" << endl;
		return 0;
	}
	if (win1)
	{
		cout << "the first player won" << endl;
		return 0;
	}
	if (win2)
	{
		cout << "the second player won" << endl;
		return 0;
	}
	if (cnt1 + cnt2 == n*n) cout << "draw" << endl;
	else if (step1) cout << "first" << endl;
	else cout << "second" << endl;
	return 0;
}