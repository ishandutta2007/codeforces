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
	int n;
	string str;
	cin >> n >> str;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '?') cnt++;
		else if (i > 0 && str[i] == str[i - 1])
		{
			puts("No");
			return 0;
		}
	}
	if (cnt == 0)
	{
		puts("No");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '?')
		{
			if (i == 0 || i == n - 1)
			{
				puts("Yes");
				return 0;
			}
			if (str[i - 1] == '?' || str[i + 1] == '?')
			{
				puts("Yes");
				return 0;
			}
			if (str[i - 1] == str[i + 1])
			{
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}