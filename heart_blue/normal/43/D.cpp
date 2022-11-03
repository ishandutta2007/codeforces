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
const int N = 1e3 + 10;
vector<int> v[N];
string ans[N];
void dfs(string& str, int& rest, int cur = 0)
{
	if (rest == 0) return;
	if (!v[cur].empty())
	{
		ans[v[cur].back()] = str;
		v[cur].pop_back();
		rest--;
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		str.push_back(i + '0');
		dfs(str, rest, cur + 1);
		str.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n * m == 2)
	{
		cout << 0 << endl;
		cout << "1 1" << endl;
		cout << n << ' ' << m << endl;
		cout << "1 1" << endl;
		return 0;
	}
	if (n % 2 == 0 && m > 1)
	{
		cout << 0 << endl;
		cout << "1 1" << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 2; j <= m; j++)
			{
				if (i & 1) cout << i << ' ' << j << endl;
				else cout << i << ' ' << m - j + 2 << endl;
			}
		}
		for (int i = n; i >= 1; i--)
		{
			cout << i << ' ' << 1 << endl;
		}
		return 0;
	}
	if (m % 2 == 0 && n != 1)
	{
		cout << 0 << endl;
		cout << "1 1" << endl;
		for (int j = 1; j <= m; j++)
		{
			for (int i = 2; i <= n; i++)
			{
				if (j & 1) cout << i << ' ' << j << endl;
				else cout << n - i + 2 << ' ' << j << endl;
			}
		}
		for (int i = m; i >= 1; i--)
		{
			cout << 1 << ' ' << i << endl;
		}
		return 0;
	}
	cout << 1 << endl;
	cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i & 1) cout << i << ' ' << j << endl;
			else cout << i << ' ' << m - j + 1 << endl;
		}
	}
	cout << "1 1" << endl;
	return 0;
}