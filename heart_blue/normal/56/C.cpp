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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ans = 0;
int ptr = 0;
string str;
map<string, int> ms;
void add(string &str)
{
	ms[str]++;
}
void del(string &str)
{
	if (ms[str]-- == 1) ms.erase(str);
}
int cnt(string &str)
{
	if (ms.count(str)) return ms[str];
	else return 0;
}
void dfs(string fa = "")
{
	string s;
	if (str[ptr] == '.' || str[ptr] == ',') return;
	while (isalpha(str[ptr]))
	{
		s += str[ptr++];
	}
	ans += cnt(s);
	add(s);
	while (str[ptr] != '.')
	{
		ptr++;
		dfs(s);
	}
	del(s);
	ptr++;
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> str;
	dfs("");
	cout << ans << endl;
	return 0;
}