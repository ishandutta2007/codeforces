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
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 2);
	str[1] = 'L';
	str[n + 1] = 'R';
	for (int i = 1; i <= n; i++)
	{
		if (str[i] != 'L') continue;
		int ok = 0;
		for (int j = i + 1; j <= n + 1; j++)
		{
			if (str[j] == 'R')
			{
				ok = j;
				break;
			}
			else if (str[j] == 'L')
				break;
		}
		for (int j = i; j <= ok; j++) a[j] = 1;
	}
	for (int i = 1; i <= n + 1; i++)
	{
		if (str[i] == 'R')
			a[i] = max(a[i], a[i - 1] + 1);
		else if (str[i] == '=')
			a[i] = a[i - 1];
	}
	for (int i = n + 1; i >= 1; i--)
	{
		if (str[i] == 'L')
			a[i - 1] = max(a[i - 1], a[i] + 1);
		else if (str[i] == '=')
			a[i - 1] = a[i];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}