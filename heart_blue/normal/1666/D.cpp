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
const int N = 1e4 + 10;
char s1[N];
char s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		int n = strlen(s1 + 1);
		int m = strlen(s2 + 1);
		int flag = 1;
		int ptr = n;
		for (int i = m; i >= 1; i--)
		{
			while (ptr > 0 && s1[ptr] != s2[i])
			{
				for (int j = 1; j <= ptr; j++)
				{
					if (s1[j] == s1[ptr])
						s1[j] = ' ';
				}
				ptr--;
			}
			if (s1[ptr] != s2[i])
			{
				flag = 0;
				break;
			}
			ptr--;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}