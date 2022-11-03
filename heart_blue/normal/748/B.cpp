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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	MEM(a, 0);
	vector<pair<char, char>> ans;
	for (int i = 0; i < n; i++)
	{
		char c1, c2;
		c1 = s1[i];
		c2 = s2[i];
		if (a[c1] || a[c2])
		{
			if (c1 != a[c2] || c2 != a[c1])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else
		{
			a[c1] = c2;
			a[c2] = c1;
			if (c1 != c2) ans.push_back({ c1,c2 });
		}
	}
	cout << ans.size() << endl;
	for (auto &p : ans)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	return 0;
}