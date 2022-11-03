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
string roman(int n)
{
	string ans;
	ans += string(n / 1000, 'M');
	n %= 1000;
	if (n >= 900) ans += "CM", n -= 900;
	if (n >= 500) ans += "D", n -= 500;
	if (n / 100 >= 1) ans += (n / 100 == 4 ? string("CD") : string(n / 100, 'C'));
	n %= 100;
	if (n >= 90) ans += "XC", n -= 90;
	if (n >= 50) ans += "L", n -= 50;
	if (n / 10 >= 1) ans += (n / 10 == 4 ? string("XL") : string(n / 10, 'X'));
	n %= 10;
	if (n >= 9) ans += "IX", n -= 9;
	if (n >= 5) ans += "V", n -= 5;
	if (n >= 1) ans += (n == 4 ? "IV" : string(n, 'I'));
	return ans;
}
LL refrain(const string& str, int b)
{
	LL ret = 0;
	for (auto& c : str)
	{
		int x = 0;
		if (isdigit(c)) x = c - '0';
		else x = c - 'A' + 10;
		ret = ret * b + x;
	}
	return ret;
}
string getans(LL n, int b)
{
	string ret;
	while (n)
	{
		int o = n % b;
		if (o < 10) ret += o + '0';
		else ret += o - 10 + 'A';
		n /= b;
	}
	reverse(ret.begin(), ret.end());
	if (ret.empty()) ret = "0";
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a;
	string b;
	string c;
	cin >> a >> b >> c;
	LL x = refrain(c, a);
	if (b == "R")
	{
		cout << roman(x) << endl;
	}
	else
	{
		cout << getans(x, stoi(b)) << endl;
	}
	return 0;
}