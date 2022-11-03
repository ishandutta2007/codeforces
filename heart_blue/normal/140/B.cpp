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
const int N = 3e2 + 10;
int a[N][N];
int ans[N];
int p[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			a[i][x] = j;
		}
	}
	MEM(ans, 0x3f);
	MEM(p, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		pos[x] = i;
	}
	int x = 1, y = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i == 2)
		{
			x = 1, y = 2;
		}
		else if (pos[y] > pos[i]) y = i;
		if (pos[x] > pos[y]) swap(x, y);
		for (int j = 1; j <= n; j++)
		{
			int key = 1;
			if (x != j) key = x;
			else if (y != j) key = y;
			else continue;
			if (a[j][key] < p[j])
			{
				p[j] = a[j][key];
				ans[j] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}