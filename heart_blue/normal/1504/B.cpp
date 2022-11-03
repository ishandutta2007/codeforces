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
		int n;
		scanf("%d", &n);
		scanf("%s%s", s1 + 1, s2 + 1);
		memset(flag, 0, sizeof(int) * (n + 1));
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s1[i] == '0') cnt++;
			else cnt--;
			if (cnt == 0) flag[i] = 1;
		}
		int ok = 1;
		int o = 0;
		for (int i = n; i >= 1; i--)
		{
			if ((s1[i] ^ o) != s2[i])
				o ^= flag[i];
			if ((s1[i] ^ o) != s2[i])
			{
				ok = 0;
				break;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}