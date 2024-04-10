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
int c[N][N];
int a[N][N];
void init()
{
	for (int i = 0; i < N; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= INF)
				c[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.rbegin(), v.rend());
		int cnt = count(v.begin(), v.end(), v[k - 1]);
		int pos = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == v[k - 1])
			{
				pos = i + 1;
				break;
			}
		}
		printf("%d\n", c[cnt][k - pos + 1]);
	}
	return 0;
}