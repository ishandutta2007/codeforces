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
const int N = 1e3 + 10;
int a[N];
void init()
{
	for (int i = 0; i < 10; i++) a[i + '0'] = i;
	for (int i = 0; i < 26; i++) a[i + 'A'] = i + 10;
}
LL check(string &s, int b)
{
	LL ret = 0;
	for (auto &c : s)
	{
		ret *= b;
		ret += a[c];
		if (a[c] >= b) return -1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	string str;
	cin >> str;
	int o = str.find(':');
	string s1 = str.substr(0, o);
	string s2 = str.substr(o + 1);
	vector<int> ans;
	for (int i = 1; i <= 1000; i++)
	{
		LL h = check(s1, i);
		LL m = check(s2, i);
		if (h >= 24) break;
		if (m >= 60) break;
		if (h >= 0 && m >= 0) ans.push_back(i);
	}
	if (ans.empty()) cout << 0 << endl;
	else if (ans.back() == 1000) cout << -1 << endl;
	else for (auto &x : ans) cout << x << ' ';
	return 0;
}