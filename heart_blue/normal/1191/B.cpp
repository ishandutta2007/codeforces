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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
void add()
{
	string s;
	cin >> s;
	int x = s[0] - '0';
	int y;
	if (s[1] == 's') y = 0;
	else if (s[1] == 'm') y = 1;
	else y = 2;
	a[y][x]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	add();
	add();
	add();
	int ans = 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int tot = 0;
			for (int k = 0; k < 3; k++)
			{
				tot += a[i][j + k] > 0;
			}
			ans = min(ans, 3 - tot);
			ans = min(ans, 3 - a[i][j]);
		}

	}
	cout << ans << endl;
	return 0;
}