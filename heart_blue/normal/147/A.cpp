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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	string s;
	for (auto &c : str)
	{
		if (isalpha(c) || c == ' ') s += c;
		else
		{
			s += ' ';
			s += c;
			s += ' ';
		}
	}
	stringstream sin(s);
	sin >> str;
	cout << str;
	while (sin >> str)
	{
		if (isalpha(str[0])) cout << ' ' << str;
		else cout << str;
	}
	return 0;
}