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
char str[N];
LL sumx[N];
LL sumy[N];
bool check(const string& s)
{
	int l = 0, r = s.length() - 1;
	while (l < r)
	{
		if (s[l] != s[r]) return false;
		l++, r--;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	if (count(str.begin(), str.end(), str[0]) >= str.length() - 1)
	{
		puts("Impossible");
		return 0;
	}
	if (str.length() & 1)
	{
		puts("2");
		return 0;
	}
	for (int i = 1; i < str.length(); i++)
	{
		string s = str.substr(i) + str.substr(0, i);
		if (!check(s)) continue;
		if (s == str) continue;
		puts("1");
		return 0;
	}
	printf("%d\n", 2);
	return 0;
}