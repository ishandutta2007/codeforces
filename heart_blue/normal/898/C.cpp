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
const int N = 3e2 + 10;
vector<string> vs[N];
vector<string> vv;
map<string, int> ms;
bool check(string &in, string &tot)
{
	if (in.length() > tot.length()) return false;
	return tot.substr(tot.length() - in.length()) == in;
}
void refrain(vector<string> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (j == i) continue;
			if (check(v[i], v[j]))
			{
				v[i] = "";
				break;
			}
		}
	}
	sort(v.rbegin(), v.rend());
	while (v.back().empty()) v.pop_back();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k = 0;
	int n;
	cin >> n;
	while (n--)
	{
		string name;
		int sz;
		cin >> name >> sz;
		if (!ms.count(name)) ms[name] = k++, vv.push_back(name);
		int o = ms[name];
		while (sz--)
		{
			string str;
			cin >> str;
			vs[o].push_back(str);
		}
	}
	for (int i = 0; i < k; i++) refrain(vs[i]);
	cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cout << vv[i] << ' ' << vs[i].size();
		for (auto &str : vs[i]) cout << ' ' << str;
		cout << endl;
	}
	return 0;
}