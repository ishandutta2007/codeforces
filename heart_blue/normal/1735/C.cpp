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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		map<char, int> mc, used;
		int rest = 26;
		for (auto& c : str)
		{
			if (mc.count(c)) c = mc[c];
			else
			{
				for (char i = 'a'; i <= 'z'; i++)
				{
					char ch = i;
					if (used[ch]) continue;
					if (rest == 1)
					{
						mc[c] = i;
						used[i] = 1;
						continue;
					}
					while (mc.count(ch)) ch = mc[ch];
					if (ch == c) continue;
					mc[c] = i;
					used[i] = 1;
					rest--;
					break;
				}
				c = mc[c];
			}
		}
		puts(str.c_str());
	}
	return 0;
}