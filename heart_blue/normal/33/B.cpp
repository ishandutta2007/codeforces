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
const int N = 5e2 + 10;
int a[N][N];
vector<pair<int, int>> ans;
void floyd(int n)
{
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	int ans = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
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
	MEM(a, 0x3f);
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() != s2.length()) puts("-1"), exit(0);
	int n;
	cin >> n;
	while (n--)
	{
		char c1, c2;
		int w;
		cin >> c1 >> c2 >> w;
		a[c1][c2] = min(a[c1][c2], w);
	}
	floyd(200);
	LL ans = 0;
	string s;
	for (int i = 0; i < s1.length(); i++)
	{
		pair<int, char> minv = make_pair(0x3f3f3f3f, '\0');
		for (char c = 'a'; c <= 'z'; c++)
		{
			minv = min(minv, { a[s1[i]][c] + a[s2[i]][c],c });
		}
		if (minv.first == 0x3f3f3f3f) puts("-1"), exit(0);
		ans += minv.first;
		s.push_back(minv.second);
	}
	printf("%lld\n", ans);
	puts(s.c_str());
	return 0;
}