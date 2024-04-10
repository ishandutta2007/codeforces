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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
char s1[N];
char s2[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		int n;
		cin >> n;
		cin >> str;
		int cnt0 = count(str.begin(), str.end(), '0');
		int cnt1 = n - cnt0;
		if (cnt1 % 2 == 1 || str[0] == '0' || str[n - 1] == '0')
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int cur0 = 0, cur1 = 0;
		string ans1, ans2;
		for (auto& c : str)
		{
			if (c == '0')
			{
				if (cur0 & 1) ans1 += '(', ans2 += ')';
				else ans1 += ')', ans2 += '(';
				cur0++;
			}
			else
			{
				if (cur1 < cnt1 / 2) ans1 += '(', ans2 += '(';
				else ans1 += ')', ans2 += ')';
				cur1++;
			}
		}
		puts(ans1.c_str());
		puts(ans2.c_str());
	}
	return 0;
}