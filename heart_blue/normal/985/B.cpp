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
int cnt[N];
char c[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
			cnt[j] += c[i][j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < m; j++)
		{
			if (cnt[j] == 1 && c[i][j] == '1')
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	
	return 0;
}