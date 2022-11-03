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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	vector<string> vs;
	cin >> str;
	if (str.front() == '.' || str.back() == '.') puts("NO"), exit(0);
	if (str.find("..") != str.npos) puts("NO"), exit(0);
	for (auto& c : str)
	{
		if (c == '.')
			c = ' ';
	}
	stringstream sin(str);
	while (sin >> str)
	{
		vs.push_back(str);
	}
	if (vs.size() == 1 || vs[0].length() > 8 || vs.back().length() > 3) puts("NO"), exit(0);
	for (int i = 1; i + 1 < vs.size(); i++)
	{
		if (vs[i].length() > 11 || vs[i].length() == 1) puts("NO"), exit(0);
	}
	cout << "YES" << endl;
	cout << vs[0] << '.';
	for (int i = 1; i + 1 < vs.size(); i++)
	{
		for (int j = 1; j <= vs[i].length(); j++)
		{
			if (j <= 3 && vs[i].length() - j <= 8)
			{
				cout << vs[i].substr(0, j) << '\n' << vs[i].substr(j) << '.';
				break;
			}
		}
	}
	cout << vs.back() << endl;
	return 0;
}