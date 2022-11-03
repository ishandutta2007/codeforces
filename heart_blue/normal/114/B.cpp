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
const int N = 1e6 + 10;
map<string, int> ms;
vector<string> vs;
int a[N];
int flag[20][20];
void init()
{
	a[0] = 0;
	for (int i = 1; i < N; i++)
	{
		a[i] = (i & 1) + a[i >> 1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vs.push_back(str);
	}
	sort(vs.begin(), vs.end());
	for (int i = 0; i < n; i++)
	{
		ms[vs[i]] = i;
	}
	while (m--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int x = ms[s1], y = ms[s2];
		flag[x][y] = flag[y][x] = 1;
	}
	pair<int, int> ans = { 0,0 };
	for (int o = 0; o < (1 << n); o++)
	{
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			if (o >> i & 1) continue;
			for (int j = 0; j < n; j++)
			{
				if (o >> j & 1) continue;
				if (flag[i][j]) f = 0;
			}
		}
		if (f) ans = max(ans, { n - a[o],o });
	}
	cout << ans.first << endl;
	int o = ans.second;
	for (int i = 0; i < n; i++)
	{
		if (o >> i & 1) continue;
		cout << vs[i] << endl;
	}
	return 0;
}