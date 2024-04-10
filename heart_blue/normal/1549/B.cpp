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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
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
		int n;
		scanf("%d", &n);
		scanf("%s%s", s1 + 1, s2 + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s2[i] == '0') continue;
			if (s1[i] == '0')
			{
				ans++;
				continue;
			}
			for (int j = i - 1; j <= i + 1; j += 2)
			{
				if (s1[j] == '1')
				{
					s1[j] = '2';
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}