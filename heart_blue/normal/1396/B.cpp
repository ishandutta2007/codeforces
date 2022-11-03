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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int o = 0;
		int pre = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		while (1)
		{
			o ^= 1;
			int key = 0;
			int maxv = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] > maxv && i != pre)
				{
					maxv = a[i];
					key = i;
				}
			}
			if (key == 0) break;
			a[key]--;
			pre = key;
		}
		if (o) puts("HL");
		else puts("T");
	}
	return 0;
}