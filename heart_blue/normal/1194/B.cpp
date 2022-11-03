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
const int N = 5e4 + 10;
const int M = 4e5 + 10;
int cnt1[N];
int cnt2[N];
char str[M];
char* p[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(cnt1, 0, sizeof(int) * n);
		memset(cnt2, 0, sizeof(int) * m);
		for (int i = 0; i < n; i++)
		{
			p[i] = str + i * m;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char& ch = p[i][j] = getchar();
				if (ch == '*') cnt1[i]++, cnt2[j]++;
				else if (ch == '.');
				else j--;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans = max(ans, cnt1[i] + cnt2[j] - (p[i][j] == '*'));
			}
		}
		printf("%d\n", n + m -1 - ans);
	}
	return 0;
}