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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[10][10];
void floyd(int n = 10)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	if (str[0] != '0') str = "0" + str;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MEM(a, 0x3f);
			LL ans = 0;
			for (int k = 0; k < 10; k++)
			{
				a[k][(k + i) % 10] = 1;
				a[k][(k + j) % 10] = 1;
			}
			floyd();
			for (int k = 0; k + 1 < str.length(); k++)
			{
				ans += a[str[k] - '0'][str[k + 1] - '0'] - 1;
			}
			if (ans > INF / 10) printf("-1 ");
			else printf("%lld ", ans);
		}
		puts("");
	}
	return 0;
}