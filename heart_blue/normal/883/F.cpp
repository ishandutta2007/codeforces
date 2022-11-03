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
const int N = 1e6 + 10;
string check(string &str)
{
	string ret;
	for (auto &c : str)
	{
		if (c == 'h')
		{
			while (!ret.empty() && ret.back() == 'k') ret.pop_back();
			ret.push_back('h');
		}
		else if (c == 'u')
		{
			ret.push_back('o');
			ret.push_back('o');
		}
		else ret.push_back(c);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n;
	map<string, int> ms;
	while (n--)
	{
		cin >> str;
		ms[check(str)] = 1;
	}
	cout << ms.size() << endl;
	return 0;
}