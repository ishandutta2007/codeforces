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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
char a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> m >> n;
	string str;
	for (int i = 0; i < n * 2; i += 2)
	{
		cin >> str;
		for (int j = 0; j < m * 2; j += 2)
		{
			char c = str[j / 2];
			a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = c;
		}
	}
	for (int j = 0; j < m * 2; j++)
	{
		for (int i = 0; i < n * 2; i++)
		{
			putchar(a[i][j]);
		}
		puts("");
	}
	return 0;
}