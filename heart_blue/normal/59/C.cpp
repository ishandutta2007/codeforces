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
const int N = 1e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	string str;
	cin >> str;
	string s;
	for (int i = 0; i < k; i++)
		s.push_back(i + 'a');
	int l = 0, r = str.length() - 1;
	while (l <= r)
	{
		if (s.find(str[r]) != s.npos) s.erase(s.find(str[r]), 1);
		if (s.find(str[l]) != s.npos) s.erase(s.find(str[l]), 1);
		if ((str[l] == '?') ^ (str[r] == '?'))
		{
			str[l] = str[r] = str[l] ^ str[r] ^ '?';
		}
		if (str[l] != str[r]) puts("IMPOSSIBLE"), exit(0);
		l++, r--;
	}
	l--, r++;
	while (l >= 0 && r < str.length())
	{
		if (str[l] == '?')
		{
			str[l] = str[r] = s.empty() ? 'a' : s.back();
			if (!s.empty()) s.pop_back();
		}
		l--, r++;
	}
	if (!s.empty()) puts("IMPOSSIBLE");
	else puts(str.c_str());
	return 0;
}