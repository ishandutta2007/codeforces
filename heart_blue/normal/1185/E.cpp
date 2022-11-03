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
const int N = 2e3 + 10;
char s1[N][N];
char s2[N][N];
int l[200], r[200], u[200], d[200];
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
		MEM(l, 0x3f);
		MEM(r, 0);
		MEM(u, 0x3f);
		MEM(d, 0);
		char maxv = 'a' - 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s1[i]);
			fill(s2[i], s2[i] + m, '.');
			for (int j = 0; j < m; j++)
			{
				char c = s1[i][j];
				if (!isalpha(c)) continue;
				l[c] = min(l[c], j);
				r[c] = max(r[c], j);
				u[c] = min(u[c], i);
				d[c] = max(d[c], i);
				maxv = max(maxv, c);
			}
		}
		int flag = 1;
		for (int c = maxv; c >= 'a'; c--)
		{
			int L = l[c];
			int R = r[c];
			int U = u[c];
			int D = d[c];
			if (L > R)
			{
				L = l[c] = l[c + 1];
				R = r[c] = r[c + 1];
				U = u[c] = u[c + 1];
				D = d[c] = d[c + 1];
			}
			if ((R - L) * (D - U) > 0) flag = 0;
		}
		for (int c = 'a'; c <= maxv; c++)
		{
			int L = l[c];
			int R = r[c];
			int U = u[c];
			int D = d[c];
			for (int i = U; i <= D; i++)
			{
				for (int j = L; j <= R; j++)
				{
					s2[i][j] = c;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s1[i][j] != s2[i][j])
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			puts("YES");
			printf("%d\n", maxv - 'a' + 1);
			for (int c = 'a'; c <= maxv; c++)
			{
				printf("%d %d %d %d\n", u[c] + 1, l[c] + 1, d[c] + 1, r[c] + 1);
			}
		}
		else
			puts("NO");
	}
	return 0;
}