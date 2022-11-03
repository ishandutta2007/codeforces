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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<string> vs;
map<string, string> ms;
void init(string& str)
{
	while (str.back() != '}') str.pop_back();
	vs.push_back(str.substr(6, str.length() - 7));
}
string refrain(string& str)
{
	int len = str.find_first_of('}') - str.find_first_of('{') - 1;
	string key = str.substr(str.find_first_of('{') + 1, len);
	ms[key] = str;
	return key;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	while (cin >> str)
	{
		if (str == "\\begin{thebibliography}{99}")
		{
			break;
		}
		if (str.substr(0, 5) == "\\cite")
		{
			init(str);
		}
	}
	getline(cin, str);
	int flag = 1;
	int o = 0;
	while (getline(cin, str))
	{
		if (str == "\\end{thebibliography}") break;
		string ret = refrain(str);
		if (ret != vs[o++])
		{
			flag = 0;
		}
	}
	if (flag)
	{
		puts("Correct");
		return 0;
	}
	puts("Incorrect");
	puts("\\begin{thebibliography}{99}");
	for (auto& s : vs)
		puts(ms[s].c_str());
	puts("\\end{thebibliography}");
	
	return 0;
}