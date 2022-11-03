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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
vector<int> v[N];
int deg[N];
bool check(string &s1, string &s2)
{
	int n = min(s1.length(), s2.length());
	if (s1.length() > s2.length() && s1.substr(0, n) == s2.substr(0, n))
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		char x = s1[i] - 'a';
		char y = s2[i] - 'a';
		if (x == y) continue;
		if (!a[x][y])
		{
			a[x][y] = 1;
			deg[y]++;
		}
		break;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int m = 26;
	string s1, s2;
	cin >> n >> s1;
	MEM(deg, 0);
	MEM(a, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> s2;
		if (!check(s1, s2))
		{
			cout << "Impossible" << endl;
			return 0;
		}
		s1 = s2;
	}
	string ans;
	while (1)
	{
		int key = -1;
		for (int i = 0; i < m; i++)
		{
			if (deg[i] == 0)
			{
				key = i;
				break;
			}
		}
		if (key == -1) break;
		ans.push_back(key + 'a');
		for (int i = 0; i < m; i++)
		{
			deg[i] -= a[key][i];
		}
		deg[key] = -1;
	}
	if (ans.length() != 26) ans = "Impossible";
	cout << ans << endl;
	return 0;
}