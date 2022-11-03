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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int cnt = 0;
		string s1, s2;
		string str1, str2;
		cin >> s1 >> s2;
		for (int i = 1; i <= s1.length() * s2.length(); i++)
		{
			if (i % s1.length() == 0 && i % s2.length() == 0)
			{
				cnt = i;
				break;
			}
		}
		while (str1.length() < cnt) str1 += s1;
		while (str2.length() < cnt) str2 += s2;
		if (str1 == str2) puts(str1.c_str());
		else puts("-1");
	}
	return 0;
}