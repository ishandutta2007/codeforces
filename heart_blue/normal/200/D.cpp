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
const int N = 5e2 + 10;
map<string, vector<vector<int>>> mv;
bool check(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == 0) continue;
		if (v1[i] != v2[i]) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	map<string, int> key, ms;
	key["string"] = 1;
	key["double"] = 2;
	key["int"] = 3;
	key["T"] = 0;
	while (n--)
	{
		getline(cin, str);
		for (auto& c : str)
		{
			if (c == ',') c = ' ';
			if (c == '(') c = ' ';
			if (c == ')') c = ' ';
		}
		stringstream sin(str);
		string name;
		sin >> name;
		sin >> name;
		vector<int> v;
		while (sin >> str)
		{
			v.emplace_back(key[str]);
		}
		mv[name].emplace_back(v);
	}
	cin >> n;
	while (n--)
	{
		string type;
		string name;
		cin >> type >> name;
		ms[name] = key[type];
	}
	cin >> n;
	getline(cin, str);
	while (n--)
	{
		getline(cin, str);
		for (auto& c : str)
		{
			if (c == '(') c = ' ';
			if (c == ')') c = ' ';
			if (c == ',') c = ' ';
		}
		vector<int> v;
		stringstream sin(str);
		string name;
		sin >> name;
		while (sin >> str)
		{
			v.emplace_back(ms[str]);
		}
		int cnt = 0;
		if (mv.count(name))
		{
			auto& vv = mv[name];
			for (auto& v1 : vv)
			{
				if (check(v1, v))
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}