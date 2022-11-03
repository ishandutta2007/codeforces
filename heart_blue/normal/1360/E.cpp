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
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
		int flag = 1;
		for(int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (str[i][j] == '0') continue;
				if (str[i + 1][j] == '1' || str[i][j + 1] == '1')
					continue;
				flag = 0;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}