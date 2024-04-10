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
		int n;
		scanf("%d", &n);
		scanf("%s", str);
		memset(flag, 0, sizeof(int) * n);
		int ptr1 = 0, ptr2 = 0;
		int rest = n;
		int ans = 0;
		while (1)
		{
			while (ptr1 < n && flag[ptr1] == 1) ptr1++;
			while (ptr1 + 1 < n && str[ptr1] != str[ptr1 + 1]) ptr1++;
			if (ptr1 + 1 >= n) break;
			ans++;
			flag[ptr1] = 1;
			rest--;
			while (ptr2 < n && flag[ptr2] == 1) ptr2++;
			if (ptr2 == n) break;
			int o = str[ptr2];
			while (ptr2 < n)
			{
				if (flag[ptr2])
				{
					ptr2++;
				}
				if (str[ptr2] != o) break;
				flag[ptr2++] = 1;
				rest--;
			}
		}
		printf("%d\n", ans + (rest + 1) / 2);
	}
	return 0;
}