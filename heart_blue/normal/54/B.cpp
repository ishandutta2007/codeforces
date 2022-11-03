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
const int N = 5e3 + 10;
vector<string> vs;
char a[21][21];
char b[21][21];
string rot(int& n, int& m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[j][i] = a[n - i - 1][j];
		}
	}
	string s;
	swap(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = b[i][j];
			s.push_back(a[i][j]);
		}
	}
	return s;
}
void refrain(string& s, int n, int m)
{
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[cur++];
		}
	}
	if (n == m)
	{
		int cnt = 4;
		while (cnt--)
		{
			s = min(s, rot(n, m));
		}
		return;
	}
	rot(n, m);
	s = min(s, rot(n, m));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vs.push_back(str);
	}
	pair<int, int> ans = { int(INF),int(INF) };
	int tot = 0;
	for (int a = 1; a <= n; a++)
	{
		if (n % a) continue;
		for (int b = 1; b <= m; b++)
		{
			if (m % b) continue;
			int flag = 1;
			map<string, int> ms;
			for (int i = 0; i < n && flag; i += a)
			{
				for (int j = 0; j < m && flag; j += b)
				{
					string str;
					for (int k = i; k < i + a; k++)
					{
						str += vs[k].substr(j, b);
					}
					refrain(str, a, b);
					if (ms.count(str))
						flag = 0;
					ms[str] = 1;
				}
			}
			tot += flag;
			if (flag) ans = min(ans, make_pair(a * b, a));
		}
	}
	printf("%d\n", tot);
	if (tot)
		printf("%d %d\n", ans.second, ans.first / ans.second);
	return 0;
}