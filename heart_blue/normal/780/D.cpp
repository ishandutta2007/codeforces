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
const int N = 1e2 + 10;
vector<string> vs;
vector<string> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;

	vs.resize(n);
	ans.resize(n);
	map<string, int> ms;
	map<string, int> vis;
	for (auto &str : vs)
	{
		string s1, s2;
		cin >> s1 >> s2;
		str = s1.substr(0, 3) + s2.substr(0, 1);
		ms[s1.substr(0, 3)]++;
	}
	for (int i = 0; i < n; i++)
	{
		string pre = vs[i].substr(0, 3);
		if (ms[pre] > 1)
		{
			string s = pre.substr(0, 2) + vs[i][3];
			ans[i] = s;
			if (vis.count(s))
			{
				cout << "NO" << endl;
				return 0;
			}
			vis[s] = 1;
		}
	}
	int o = n;
	while (o--)
	{
		for (int i = 0; i < n; i++)
		{
			if (ans[i].empty())
			{
				string s1 = vs[i].substr(0, 3);
				string s2 = vs[i].substr(0, 2) + vs[i][3];
				int o1 = vis.count(s1);
				int o2 = vis.count(s2);
				if (o1 | o2)
				{
					if (o1 & o2)
					{
						cout << "NO" << endl;
						return 0;
					}
					if (o1) ans[i] = s2, vis[s2] = 1;
					else ans[i] = s1, vis[s1] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i].empty()) ans[i] = vs[i].substr(0, 3);
	}
	puts("YES");
	for (auto &str : ans) puts(str.c_str());
	return 0;
}