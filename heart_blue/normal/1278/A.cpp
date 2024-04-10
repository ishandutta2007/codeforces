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
int flag[N];
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
		sort(s1.begin(), s1.end());
		int flag = 0;
		for (int i = 0; i + s1.length() <= s2.length(); i++)
		{
			string s = s2.substr(i, s1.length());
			sort(s.begin(), s.end());
			if (s == s1)
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}