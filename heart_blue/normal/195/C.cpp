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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<string>  refrain(string& str)
{
	vector<string> ret;
	if (str.empty()) return ret;
	str.erase(0, str.find_first_not_of(' '));
	if (str.empty()) return ret;
	str.erase(str.find_last_not_of(' ') + 1);
	if (str[1] == 'r')
	{
		ret.push_back(str);
	}
	else if (str[1] == 'h')
	{
		for (auto& c : str)
		{
			if (c == '(') c = ' ';
			if (c == ')') c = ' ';
		}
		stringstream sin(str);
		while (sin >> str)
			ret.push_back(str);
	}
	else if (str[1] == 'a')
	{
		int l = str.find_first_of("\"");
		int r = str.find_last_of("\"");
		string s = str.substr(l + 1, r - l - 1);
		str.erase(l);
		for (auto& c : str)
		{
			if (c == '(') c = ' ';
			if (c == ',') c = ' ';
			if (c == '(') c = ' ';
		}
		stringstream sin(str);
		while (sin >> str)
			ret.push_back(str);
		ret.push_back(s);
	}
	return ret;
}
string dfs()
{
	string str;
	string ret;
	vector<string> vs;
	while (getline(cin, str))
	{
		vs = refrain(str);
		if (vs.empty()) continue;
		if (vs[0] == "try")
		{
			auto res = dfs();
			if (!res.empty())
				ret = res;
		}
		else if (vs[0] == "throw") ret = vs[1];
		else break;
	}
	if (ret == vs[1]) cout << vs[2] << endl, exit(0);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	while (getline(cin, str))
	{
		if (refrain(str).size() == 1)
			dfs();
	}
	cout << "Unhandled Exception" << endl;
	return 0;
}