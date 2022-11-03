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
const int N = 2e3 + 10;
int a[N][N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int k;
	cin >> k;
	a[2][3] = a[3][2] = a[4][2] = a[2][4] = 1;
	key[0] = 3;
	int cur = 5;
	for (int i = 1; i < 30; i++)
	{
		a[cur][cur - 1] = a[cur - 1][cur] = 1;
		a[cur][cur - 2] = a[cur - 2][cur] = 1;
		a[cur + 1][cur - 1] = a[cur - 1][cur + 1] = 1;
		a[cur + 1][cur - 2] = a[cur - 2][cur + 1] = 1;
		key[i] = cur;
		cur += 2;
	}
	for (int i = 0; i < 30; i++)
	{
		if (k >> i & 1)
		{
			int x = 1;
			for (int j = 0; j < 30 - i; j++)
			{
				a[x][cur] = a[cur][x] = 1;
				x = cur++;
			}
			a[x][key[i]] = a[key[i]][x] = 1;
		}
	}
	cout << cur - 1 << endl;
	for (int i = 1; i < cur; i++)
	{
		for (int j = 1; j < cur; j++)
		{
			printf("%c", "NY"[a[i][j]]);
		}
		puts("");
	}
	return 0;
}