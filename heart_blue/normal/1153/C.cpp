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
const int N = 1e3 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	if (n & 1)
	{
		puts(":(");
		return 0;
	}
	int l = count(str.begin(), str.end(), '(');
	int r = count(str.begin(), str.end(), ')');
	int left = n - l - r;
	if (abs(l - r) > left)
	{
		puts(":(");
		return 0;
	}
	int rr = n / 2 - r;
	int ll = n / 2 - l;
	int o = 0;
	int tot = 0;
	for (auto& c : str)
	{
		tot++;
		if (c == '?')
		{
			if (ll) ll--, c = '(';
			else if (rr) rr--, c = ')';
		}
		if (c == '(') o++;
		else o--;
		if (o <= 0 && tot < n) puts(":("), exit(0);
	}
	puts(str.c_str());
	return 0;
}