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
const int N = 4e5 + 10;
string tostr(LL n)
{
	string str;
	while (n) str.push_back(n % 10 + '0'), n /= 10;
	reverse(str.begin(), str.end());
	return str;
}
LL toint(string &str)
{
	LL ret = 0;
	for (auto &c : str) ret = ret * 10 + c - '0';
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		str = str.substr(4);
		LL o = 10;
		LL cur = 1989;
		for (int i = 1; i < str.length(); i++)
		{
			cur += o;
			o *= 10;
		}
		string s = "0" + tostr(cur);
		s = s.substr(0, s.length() - str.length()) + str;
		LL x = toint(s);
		while (x < cur) x += o;
		cout << x << endl;
	}
	return 0;
}