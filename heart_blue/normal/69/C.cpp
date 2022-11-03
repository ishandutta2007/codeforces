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
const int N = 2e5 + 10;
map<string, vector<pair<string, int>>> mv;
map<string, int> ms[N];
void add(map<string, int> &ms, const string& str, int val = 1)
{
	ms[str] += val;
}
void del(map<string, int> &ms, const string& str, int val = 1)
{
	ms[str] -= val;
	if (ms[str] == 0)
		ms.erase(str);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k, n, m, q;
	scanf("%d%d%d%d", &k, &n, &m, &q);
	while (n--) scanf("%*s");
	string s;
 	getline(cin, s);
	while (m--)
	{
		getline(cin, s);
		for (auto& c : s)
		{
			if (c == ':') c = ' ';
			if (c == ',') c = ' ';
		}
		string str;
		stringstream sin(s);
		sin >> str;
		auto &v = mv[str];
		int cnt;
		while (sin >> str >> cnt)
		{
			v.emplace_back(str, cnt);
		}
	}
	while (q--)
	{
		int id;
		string str;
		cin >> id >> str;
		add(ms[id], str);
		for (auto& p : mv)
		{
			int flag = 1;
			auto& v = p.second;
			for (auto& pp : v)
			{
				if (!ms[id].count(pp.first) || ms[id][pp.first] < pp.second)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				for (auto& pp : v)
				{
					del(ms[id], pp.first, pp.second);
				}
				add(ms[id], p.first);
			}
		}
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d\n", ms[i].size());
		for (auto& p : ms[i])
		{
			printf("%s %d\n", p.first.c_str(), p.second);
		}
	}
	return 0;
}