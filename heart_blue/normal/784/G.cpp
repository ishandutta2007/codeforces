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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
const int M = 5e5 + 10;
int check(string &str)
{
	int cur = 0;
	int sum = 0;
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (flag) sum -= cur;
			else sum += cur;
			if (str[i] == '+') flag = 0;
			else flag = 1;
			cur = 0;
		}
		else
		{
			cur = cur * 10 + str[i] - '0';
		}
	}
	if (flag) sum -= cur;
	else sum += cur;
	return sum;
}
void output(char &cur, char to)
{
	if (cur > to) cout << string(cur - to, '-');
	else cout << string(to - cur, '+');
	cout << '.' << endl;
	cur = to;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;

	cout << "++>" << endl
		 << "+++>" << endl
		 << "<[<+>-]<" << endl
		 << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
	int sum = check(str);
	char cur = '0';
	if (sum < 0)
	{
		output(cur, '-');
	}
	string s;
	sum = abs(sum);
	while (sum)
	{
		s.push_back(sum % 10 + '0');
		sum /= 10;
	}
	if (s.empty()) s.push_back('0');
	reverse(s.begin(), s.end());
	for (auto &c : s) output(cur, c);
	return 0;
}