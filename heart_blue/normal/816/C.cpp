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
const int N = 5e2 + 10;
int a[N][N];
int b[N][N];
int row[N];
int col[N];
int n, m;
bool check(int x)
{
	memcpy(b, a, sizeof(b));
	MEM(row, 0);
	MEM(col, 0);
	row[1] = x;
	for (int i = 1; i <= m; i++)
	{
		b[1][i] -= x;
		col[i] = b[1][i];
		if (col[i] < 0) return false;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] -= col[j];
			if (b[i][j] < 0) return false;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		row[i] = b[i][1];
		for (int j = 1; j <= m; j++)
		{
			if (row[i] != b[i][j])
			{
				return false;
			}
		}
	}
	return true;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	int key = -1;
	int ans = INF;
	for (int i = 0; i < N; i++)
	{
		if (check(i))
		{
			int tot = 0;
			for (int i = 1; i <= n; i++) tot += row[i];
			for (int i = 1; i <= m; i++) tot += col[i];
			if (tot < ans)
			{
				ans = tot;
				key = i;
			}
			
		}
	}
	if(key == -1) puts("-1");
	else
	{
		check(key);
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
		{
			while (row[i]--)
				printf("row %d\n", i);
		}
		for (int i = 1; i <= m; i++)
		{
			while (col[i]--)
				printf("col %d\n", i);
		}
		return 0;
	}
	return 0;
}