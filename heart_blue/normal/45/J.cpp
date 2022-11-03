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
const int N = 1e2 + 10;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[N][N];
void check(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int o = 0; o < 4; o++)
			{
				int x = a[i][j];
				int y = a[i + dx[o]][j + dy[o]];
				if (abs(x - y) == 1) return;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d%c", a[i][j], " \n"[j == m]);
		}
	}
	exit(0);
}
void solve(vector<int>& v, int n, int m)
{
	random_shuffle(v.begin(), v.end());
	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = v[ptr++];
		}
	}
	check(n, m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(a, 0x3f);
	vector<int> v;
	for (int i = 1; i <= n * m; i++) v.push_back(i);
	int cnt = 1000;
	while (cnt--)
	{
		solve(v, n, m);
	}
	puts("-1");
	return 0;
}