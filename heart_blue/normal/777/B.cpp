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
const int N = 1e6 + 10;
int getans1(string &s1, string &s2)
{
	list<char> l1(s1.begin(), s1.end());
	list<char> l2(s2.begin(), s2.end());
	int ret = 0;
	while (!l1.empty() && !l2.empty())
	{
		if (l1.back() < l2.back()) l1.pop_front(), l2.pop_back(), ret++;
		else l1.pop_back(), l2.pop_back();
	}
	return ret;
}
int getans2(string &s1, string &s2)
{
	list<char> l1(s1.begin(), s1.end());
	list<char> l2(s2.begin(), s2.end());
	int ret = 0;
	while (!l1.empty() && !l2.empty())
	{
		if (l1.front() >= l2.front()) l1.pop_back(), l2.pop_front();
		else l1.pop_front(), l2.pop_front(), ret++;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for (auto &c : s1) c = '9' - (c - '0');
	for (auto &c : s2) c = '9' - (c - '0');
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	cout << getans1(s1, s2) << endl;
	cout << getans2(s2, s1) << endl;
	return 0;
}