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
const int N = 3e5 + 10;
int check(char a, char b, string& s)
{
	if (a == b)
	{
		return count(s.begin(), s.end(), a);
	}
	int ans = 0;
	for (auto& c : s)
	{
		if (c == a)
		{
			swap(a, b);
			ans++;
		}
	}
	return ans - (ans & 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int ans = 0;
		for (char a = '0'; a <= '9'; a++)
		{
			for (char b = '0'; b <= '9'; b++)
			{
				ans = max(ans, check(a, b, str));
			}
		}
		printf("%d\n", str.length() - ans);
	}
	return 0;
}