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
const int N = 5e1 + 10;
char ans[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(ans, 0);
		string str;
		int n;
		cin >> n;
		cin >> str;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '2')
				v.push_back(i);
		}
		if (v.size() == 1 || v.size() == 2)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		if (!v.empty()) v.push_back(v[0]);
		for (int i = 0; i + 1 < v.size(); i++)
		{
			int x = v[i];
			int y = v[i + 1];
			ans[x][y] = '+';
			ans[y][x] = '-';
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) ans[i][j] = 'X';
				if (ans[i][j] == 0)
					ans[i][j] = '=';
			}
			puts(ans[i]);
		}
	}
	return 0;
}