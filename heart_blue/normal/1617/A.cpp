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
const int N = 5e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		map<char, int> mc;
		for (auto& c : s1)
			mc[c]++;
		if (s2 == "abc" && mc['a'] * mc['b'] * mc['c'] != 0) s2 = "acb";
		else s2 = "abc";
		for (int i = 'd'; i <= 'z'; i++) s2 += i;
		for (auto& c : s2)
		{
			int cnt = mc[c];
			while (cnt--) putchar(c);
		}
		puts("");
	}
	return 0;
}