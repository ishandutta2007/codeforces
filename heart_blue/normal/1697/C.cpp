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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		int n;
		cin >> n;
		cin >> s1 >> s2;
		int flag = 1;
		int lastb = n;
		int lasta = n;
		while (!s1.empty())
		{
			if (s1.back() == s2.back())
			{
				s1.pop_back();
				s2.pop_back();
				n--;
				continue;
			}
			if (s1.length() == 1)
			{
				flag = 0;
				break;
			}
			if (s1.back() == 'c')
			{
				for (int i = min(lastb, n - 1); i >= 0; i--)
				{
					if (s1[i] == 'b')
					{
						lastb = i;
						swap(s1[i], s1[n - 1]);
						break;
					}
					if (s1[i] == 'a') break;
				}
			}
			else if (s1.back() == 'b')
			{
				for (int i = min(n - 2, lasta); i >= 0; i--)
				{
					if (s1[i] == 'a')
					{
						swap(s1[i], s1[n - 1]);
						lasta = i;
						break;
					}
					if (s1[i] == 'c')
						break;
				}
			}
			if (s1.back() != s2.back())
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}

	return 0;
}