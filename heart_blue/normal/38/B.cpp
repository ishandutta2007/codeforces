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
const int N = 5e4 + 10;
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };
int flag[10][10];
void check1(string str)
{
	int x = str[0] - 'a';
	int y = str[1] - '1';
	for (int i = 0; i < 8; i++)
	{
		flag[i][y] = flag[x][i] = 1;
	}
}
void check2(string str)
{
	int x = str[0] - 'a';
	int y = str[1] - '1';
	flag[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx >= 8) continue;
		if (ty < 0 || ty >= 8) continue;
		flag[tx][ty] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, 0);
	string s1, s2;
	cin >> s1 >> s2;
	check1(s1);
	check2(s1);
	check2(s2);
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ans += flag[i][j] ^ 1;
		}
	}
	cout << ans << endl;
	return 0;
}