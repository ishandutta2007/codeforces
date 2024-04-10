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
const int N = 1e2 + 10;
char c[4][N][N];
int n;
int getcnt(int o)
{
	int ret = 0;
	while (o) o -= o & -o, ret++;
	return ret;
}
int check(char c[N][N], int o)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int oo = ((i + j) & 1) ^ o;
			if (oo != c[i][j] - '0') cnt++;
		}
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++) cin >> c[i][j];
	}
	int ans = INF;
	for (int o = 0; o < 16; o++)
	{
		if (getcnt(o) != 2) continue;
		int sum = 0;
		for (int i = 0; i < 4; i++) sum += check(c[i], o >> i & 1);
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}