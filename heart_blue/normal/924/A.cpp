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
const int N = 4e6 + 10;
const int M = 2e7 + 10;
bool check(string &s1, string &s2)
{
	int n = s1.length();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '#' && s2[i] == '#')
		{
			return s1 == s2;
		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> vs(n);
	for (auto &s : vs) cin >> s;
	for (auto &s1 : vs)
	{
		for (auto &s2 : vs)
		{
			if (!check(s1, s2))
			{
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}