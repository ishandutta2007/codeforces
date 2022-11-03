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
const int N = 2e2 + 10;
char str[N][N];
int dx[] = { 1,1,1,2 };
int dy[] = { -1,0,1,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (str[i][j] == '#') continue;
			int tot = 0;
			for (int k = 0; k < 4; k++)
			{
				tot += str[i + dx[k]][j + dy[k]] == '.';
			}
			if (tot != 4) puts("NO"), exit(0);
			for (int k = 0; k < 4; k++)
			{
				str[i + dx[k]][j + dy[k]] = '#';
			}
		}
	}
	puts("YES");
	return 0;
}